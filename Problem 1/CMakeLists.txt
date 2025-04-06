cmake_minimum_required(VERSION 3.28)
project(Problem_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})

add_executable(Problem_1
        main.cpp)

target_link_libraries(Problem_1 ${CURL_LIBRARIES})