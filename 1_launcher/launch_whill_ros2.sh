#! /usr/bin/bash
if [[ ! "${TAG}" == image_* ]]; then
  echo "Build first"
  bash
else
  $(echo "exec ros2 launch connection_wheelchair connection_wheelchair.launch.py --remap __ns:=/$HOSTNAME")
fi
