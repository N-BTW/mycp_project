#!/bin/bash

# --------------------------------------------
# system_call_analysis.sh
# Write a shell script to compare system calls made by mycp and cp
# Follow the hints below to complete each step
# --------------------------------------------

# Step 1: Print a message saying you're tracing mycp
# Hint: Use echo to print "Running system call trace for mycp..."
echo "Running system call trace for mycp..."

# Step 2: Use the strace tool to trace the system calls made by ./mycp
# Hint: Use strace with the -c option to show a summary of system calls
# Hint: Use the -f flag with ./mycp and provide two filenames: source and destination
# Hint: Redirect both stdout and stderr to a file named mycp_trace.txt
strace -c -f ./mycp -f file1.txt file2.txt > mycp_trace.txt 2>&1

# Step 3: Print a message saying you're tracing cp
# Hint: Use echo again to indicate the cp trace is running
echo "Running system call trace for cp..."

# Step 4: Use strace to trace the standard cp command
# Hint: Use similar options as above, with input/output files
# Hint: Redirect the output to cp_trace.txt
strace -c -f cp -f file1.txt file3.txt > cp_trace.txt 2>&1

# Step 5: Print a message confirming that the traces were saved
# Hint: Use echo to notify the user that results are in both trace files
echo "System call traces saved to mycp_trace.txt and cp_trace.txt."