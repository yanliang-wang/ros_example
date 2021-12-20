cmake_minimum_required(VERSION 2.8.3)
project(concurrency_demo)


find_package(catkin_simple REQUIRED)
catkin_simple(ALL_DEPS_REQUIRED)

cs_add_executable(concurrency_pub src/concurrency_pub.cpp)
cs_add_executable(sub_ros_spin src/sub_ros_spin.cpp)
cs_add_executable(sub_MultiThreadedSpinner src/sub_MultiThreadedSpinner.cpp)
cs_add_executable(sub_AsyncSpinner src/sub_AsyncSpinner.cpp)
cs_add_executable(sub_callback_queue src/sub_callback_queue.cpp)

cs_export()