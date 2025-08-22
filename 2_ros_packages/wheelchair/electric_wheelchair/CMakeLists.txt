cmake_minimum_required(VERSION 3.8)
project(electric_wheelchair)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 必要な依存をすべて記述（順番が重要）
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(xacro REQUIRED)

set(XACRO_IN   "${CMAKE_CURRENT_SOURCE_DIR}/xacro/wheelchair_2.xacro")
set(URDF_OUT   "${CMAKE_CURRENT_BINARY_DIR}/wheelchair.urdf")

# add_custom_command(
#   OUTPUT ${URDF_OUT}
#   COMMAND xacro ${XACRO_IN} -o ${URDF_OUT}
#   DEPENDS ${XACRO_IN}
# )
add_custom_command(
  OUTPUT ${URDF_OUT}
  COMMAND xacro --inorder ${XACRO_IN} for_gazebo:=false gpu:=true organize_cloud:=false -o ${URDF_OUT}
  DEPENDS ${XACRO_IN}
)





# ALL をつけると「デフォルトビルド target」に URDF 生成が入ります
add_custom_target(generate_wheelchair_urdf
  ALL
  DEPENDS ${URDF_OUT}
)

# install 時に urdf/ ディレクトリを作ってその中にコピー
install(FILES ${URDF_OUT}
        DESTINATION share/${PROJECT_NAME}/urdf)


# 実行可能ファイルの定義
add_executable(electric_wheelchair_node src/electric_wheelchair.cpp)

ament_target_dependencies(electric_wheelchair_node
  rclcpp
  std_msgs
  geometry_msgs
  nav_msgs
)

install(TARGETS
  electric_wheelchair_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)

# install(DIRECTORY xacro
#   DESTINATION share/${PROJECT_NAME}
# )

# Install mesh files
install(DIRECTORY xacro/
  DESTINATION share/${PROJECT_NAME}/xacro
)

# install(DIRECTORY model.config model.sdf
#   DESTINATION share/${PROJECT_NAME}
# )

install(DIRECTORY models/
  DESTINATION share/${PROJECT_NAME}/models
)

install(FILES config/controller.yaml
  DESTINATION share/${PROJECT_NAME}/config
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()