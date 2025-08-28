#! /usr/bin/bash +x
source $ACSL_ROS2_DIR/bashrc
echo $PROJECT
echo $ROS_DOMAIN_ID

cd $ACSL_ROS2_DIR/0_host_commands/scripts/
RMW=cyclonedds dup rtk_gnss
RMW=cyclonedds dup whill
RMW=cyclonedds dup velodyne run
