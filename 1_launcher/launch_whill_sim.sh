#! /usr/bin/bash
source /root/.bashrc
printenv | grep GAZEBO
ros2 launch connection_wheelchair connection_wheelchair.launch.py 
  #--remap __ns:=/$HOSTNAME
 
