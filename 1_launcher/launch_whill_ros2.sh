#! /usr/bin/bash
  #$(echo "exec 
  # source /root/.bashrc
  #")
  source /root/.bashrc
  echo "export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$(ros2 pkg prefix electric_wheelchair)/share/electric_wheelchair/models:$(ros2 pkg prefix create_world)/share/create_world/models" >> ~/.bashrc
bash
 # ros2 launch connection_wheelchair connection_wheelchair.launch.py 
  #--remap __ns:=/$HOSTNAME
 
