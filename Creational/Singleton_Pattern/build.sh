#!/bin/bash

BUILD_DIR=build
PROJECT_NAME=$(grep -Po '(?<=project\().*?(?=\))' CMakeLists.txt)

if [ ! -d "$BUILD_DIR" ]; then
    echo "Creating build directory..."
    mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR"

if cmake ..; then
    echo "CMake configuration successful."
    make
    if [ $? -eq 0 ]; then
        echo "Build successful."
        cp "$PROJECT_NAME" "../$PROJECT_NAME"
    else
        echo "Build failed."
        exit 1
    fi
else
    echo "CMake configuration failed."
    exit 1
fi
