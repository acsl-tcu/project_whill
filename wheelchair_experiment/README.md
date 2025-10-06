# Wheelchair Navigation System

## How to Use

### Step 1: Set Wheelchair Mode

Open `main_astar.m` and configure the operation mode:

```matlab
mode = 2;  % Choose operation mode:
           % 2: Gazebo physics simulation (AVAILABLE)
           % 3: Real hardware experiment (AVAILABLE)
           % Note: Only modes 2 and 3 are currently available
```

### Step 2: Configure Sensors and Autoware

Set the sensors and autoware according to your chosen mode:

```matlab
% For Mode 2 (Gazebo):
sensor(1) = true;   % Prime sensor (Gazebo)
sensor(2) = true;   % LiDAR (Gazebo, online)
sensor(3) = false;  % RealSense
autoware(1) = false; % Autoware disabled for Gazebo

% For Mode 3 (Real Hardware):
sensor(1) = false;  % Prime (not used for real hardware)
sensor(2) = true;   % LiDAR (Gazebo, online) 
sensor(3) = false;  % RealSense
autoware(1) = true;  % Autoware enabled for real hardware
```

### Step 3: Run the Program

```matlab
run('main_astar.m')
```

## Control Modes (Interactive Menu)

During simulation, you can press any key to access the control mode menu:

### Available Control Modes

1. **Floor Change Mode**
   - Creates a path to the elevator and enters the elevator
   - Full autonomous navigation to elevator with entry capability
   - Enables LiDAR tracking and obstacle avoidance

2. **Door Detection Debug Mode** 
   - Used specifically to test door detection algorithms
   - Bypasses normal navigation and focuses on door detection testing
   - Useful for algorithm development and validation

3. **NDT Pose Detection Mode**
   - Manual control with continuous pose broadcasting
   - Use manual controls to move wheelchair while displaying pose data
   - Useful for calibration and testing

4. **Floor Change Mode WITHOUT Estimator**
   - Enables path following but disables LiDAR processing and tracking
   - Navigation only without obstacle detection

5. **Exit Simulation**
   - Terminates the simulation

### Using the Interactive Menu

1. While simulation is running, press any key
2. Choose from options 1-5 in the menu
3. The wheelchair will switch to the selected mode
4. Press any key again to access the menu at any time

## Quick Start Example

```matlab
% For Gazebo simulation:
mode = 2;
sensor(1) = true;   % Prime
sensor(2) = true;   % LiDAR  
sensor(3) = false;  % RealSense
autoware(1) = false; % Autoware disabled

% For Real Hardware:
mode = 3;
sensor(1) = false;  % Prime disabled
sensor(2) = true;   % LiDAR enabled
sensor(3) = false;  % RealSense disabled  
autoware(1) = true;  % Autoware enabled

% Then run:
run('main_astar.m')

% During simulation, press any key to access the control mode menu
```