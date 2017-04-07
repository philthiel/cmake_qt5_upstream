cmake_policy(SET CMP0048 NEW)
project("MyAPP" VERSION 1.2.0)


CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0 FATAL_ERROR)


find_package(MyLIB)


add_executable(MyAPP ${PROJECT_SOURCE_DIR}/myapp.C)
target_link_libraries(MyAPP MyLIB)



