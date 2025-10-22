# Todo List

- [ ] **Fix waypoint selection after door transition:**
    - [ ] Modify `PhaseManager.m` to ensure the waypoint index is reset to 1 after a door transition.
    - [ ] Verify that the `update` function in `PhaseManager.m` correctly handles the waypoint index after the fix.
    - [ ] Test the fix in a simulation or on the actual wheelchair to confirm that it correctly navigates into the next room and follows the new path from the beginning.