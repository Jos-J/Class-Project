#!/bin/bash
# Compile test runner
g++ -o tests/test-runner tests/test.cpp student.cpp roster.cpp

# Check if compilation succeeded
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run the test runner
./tests/test-runner

# Keep terminal open if running in Git Bash
read -p "Press [Enter] to continue..."
