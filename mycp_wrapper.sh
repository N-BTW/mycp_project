#!/bin/bash

# This script builds and runs the mycp utility
echo "Compiling the project..."
make

if [ $? -eq 0 ]; then
    echo "Build successful. Running mycp with arguments: $@"
    ./mycp "$@"
else
    echo "Build failed."
fi