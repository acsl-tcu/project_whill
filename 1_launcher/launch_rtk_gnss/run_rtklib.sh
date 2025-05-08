#! /usr/bin/bash
#RTKLIB: communication between base and mobile station
$(echo "exec /root/ros2_ws/src/RTKLIB/app/str2str/gcc/str2str -in tcpcli://133.78.211.29:4000 -out serial://ttyUSB-ublox:23400")
