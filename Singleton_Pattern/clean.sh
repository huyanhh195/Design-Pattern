#!/bin/bash

BUILD_DIR=build
PROJECT_NAME=$(grep -Po '(?<=project\().*?(?=\))' CMakeLists.txt)

if [ -d "$BUILD_DIR" ]; then
    echo "Removing build directory..."
    rm -rf "$BUILD_DIR"
    rm -rf "$PROJECT_NAME"
    clear
fi