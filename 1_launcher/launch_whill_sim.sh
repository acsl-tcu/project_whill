#! /usr/bin/bash
sleep 3
source /root/.bashrc
printenv | grep GAZEBO
cat /root/.bashrc
sleep 2
ros2 launch connection_wheelchair connection_wheelchair.launch.py 
  #--remap __ns:=/$HOSTNAME
 
