cmake_minimum_required(VERSION 3.0.0)
project(vesc_ethercat_packet_test VERSION 0.1.0)

add_executable(test src/main.cpp)

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/includes)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
