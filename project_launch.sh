#! /usr/bin/bash +x
source /home/dstudent/.bashrc
echo $PROJECT
echo $ROS_DOMAIN_ID

$ACSL_ROS2_DIR/0_host_commands/scripts/dup rtk_gnss
$ACSL_ROS2_DIR/0_host_commands/scripts/dup whill
$ACSL_ROS2_DIR/0_host_commands/scripts/dup velodyne run
