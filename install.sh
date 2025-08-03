#!/bin/bash

# 'set -e' makes the script stop immediately if any command fails (returns a non-zero exit code).
set -e

# Check if cmake is installed on the system
if ! command -v cmake &> /dev/null
then
    # If CMake is not installed, print an error message and exit the script.
    echo "Error: CMake is not installed. Please install CMake."
    exit 1
fi

# Remove the existing 'build' directory (if it exists) to ensure the build process starts fresh.
rm -rf build bin

# Configure the project with CMake.
# The current directory (.) contains the CMakeLists.txt file, and the 'build' directory will be created
# to store temporary configuration and build files.
cmake -S . -B build

# Build the project from the 'build' directory.
# CMake will invoke the compiler according to the settings in the CMakeLists.txt file.
cmake --build build

# Copy the generated 'darlingdle' executable from the 'build' directory to '/usr/local/bin'.
# This allows you to run 'darlingdle' globally from anywhere in the terminal.
#sudo cp ./bin/darlingdle  /usr/local/bin