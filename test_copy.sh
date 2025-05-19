#!/bin/bash
# --------------------------------------------------
# test_copy.sh - Script to test the functionality of mycp
# This script performs the following steps:
# 1. Creates a sample file named file1.txt
# 2. Uses the mycp program to copy it to file2.txt
# 3. Compares the two files using the diff command
# 4. Logs the result to test_log.txt (which can be added to README.md)
# --------------------------------------------------

# Step 1: Create a sample file to test copying
echo "This is a test for copying files using mycp." > file1.txt

# Step 2: Run the mycp program to copy the file
./mycp file1.txt file2.txt

# Step 3: Compare the original and copied files using diff
if diff file1.txt file2.txt > /dev/null; then
    echo "Test Passed: file copied successfully."
    echo "Test Passed: file1.txt == file2.txt" >> test_log.txt
else
    echo "Test Failed: copied file does not match the original."
    echo "Test Failed: file1.txt != file2.txt" >> test_log.txt
fi