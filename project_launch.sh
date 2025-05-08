#! /usr/bin/bash +x
source $ACSL_ROS2_DIR/bashrc
echo $PROJECT
echo $ROS_DOMAIN_ID

cd $ACSL_ROS2_DIR/0_host_commands/scripts/
dup rtk_gnss ublox_launch
dup rtk_gnss run
dup whill
dup velodyne run
