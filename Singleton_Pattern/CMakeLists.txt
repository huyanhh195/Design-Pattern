cmake_minimum_required(VERSION 3.10)

project(MyDatabaseSingleton)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES main.cpp)

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCES})