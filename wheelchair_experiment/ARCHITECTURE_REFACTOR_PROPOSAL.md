# Architecture Refactoring Proposal for Phase Management

This document outlines a proposal to refactor the wheelchair's phase management system to improve its structure, clarity, and extensibility.

## 1. Problem Statement

The current phase management system has several architectural issues:

*   **Scattered Logic:** Phase transition logic is spread across multiple files (`PhaseManager.m`, `Control.m`, `Estimate.m`), making it difficult to understand the overall state flow.
*   **Confusing Class Responsibilities:** The `SharedControlMode.m` class is misleadingly named, as it primarily functions as a data container for waypoints rather than managing the control mode. The `Estimate.m` module currently triggers phase transitions, blurring the line between estimation and state management.
*   **Tight Coupling:** The `Estimator` and `Control` modules are tightly coupled with the phase transition logic. For example, the `Control` module directly sets the phase to `completed`.

## 2. Proposed Architecture

To address these issues, we propose a new centralized architecture where the `PhaseManager` acts as the sole decision-maker (a "brain") for phase transitions. It will do this by observing a central data object, `NavigationContext`.

The new data flow will be as follows:

1.  **`Estimator` and `Control` Report Status:** Both modules will perform their primary tasks (estimation and control) and then report their results and status into a shared `NavigationContext` object.
2.  **`PhaseManager` Makes Decisions:** The `PhaseManager` will read the data from the `NavigationContext`. It will contain all the logic to evaluate the current situation (e.g., "target reached" AND "door open") and decide if a phase change is necessary.
3.  **Modules Obey the Phase:** The `PhaseManager` will set the new global phase. The `Estimator` and `Control` modules will read this phase and adjust their behavior accordingly (e.g., `Control` switches from "path following" to "elevator entry" behavior).

### Key Components

*   **`NavigationContext` (New):** A central `handle` class that acts as a "live" data bus.
    *   **Contains:** All relevant real-time data, such as the wheelchair's pose, detected objects, whether the target is reached, if the system is stalled, etc.
    *   **Updated by:** `Estimator` and `Control`.
    *   **Read by:** `PhaseManager`.

*   **`PhaseManager` (Refactored):** The central decision-maker for the system's state.
    *   **Responsibility:** To monitor the `NavigationContext` and decide when to transition to a new phase. It will contain the complete state machine logic.

*   **`Estimator` and `Control` (Refactored):** Pure "doers" that focus on their specific tasks.
    *   **Responsibility:**
        1.  Check the current phase from `PhaseManager`.
        2.  Execute their tasks based on that phase (e.g., track objects, calculate motor commands).
        3.  Report their status and results to the `NavigationContext`.
    *   They will **no longer** contain any logic for deciding on phase transitions.

## 3. Benefits of the New Architecture

*   **Centralization & Clarity:** All state transition logic will be in one place (`PhaseManager`), making the system's behavior much easier to understand and debug.
*   **Decoupling & Modularity:** `Estimator` and `Control` will be decoupled from the state management logic. They will only need to know how to report their status.
*   **Extensibility:** Adding new phases or changing transition conditions will only require modifications to `PhaseManager`, without affecting other modules. This makes the system much easier to maintain and expand.

## 4. Implementation Steps

1.  **Create `NavigationContext.m`:** Define the new central data-sharing class.
2.  **Integrate `NavigationContext`:** Pass an instance of `NavigationContext` to the `Estimator`, `Control`, and `PhaseManager`.
3.  **Refactor `Estimator` and `Control`:** Modify them to report their status to `NavigationContext` instead of making phase decisions.
4.  **Refactor `PhaseManager`:** Rewrite the `checkTransitions` logic to use the data from `NavigationContext` to make all phase change decisions.
