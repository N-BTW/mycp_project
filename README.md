# mycp_project

A simple file copy utility implemented in C using system calls.

## Project Structure

```
  mycp_project/
  |── Makefile # Build system for the project
  ├── README.md # Project documentation
  ├── mycp.h # Header file for the copy utility
  ├── mycp.c # Implements the file copy logic
  ├── file_ops.h # Header file for file operations
  ├── file_ops.c # Implements file operations
  ├── main.c # Driver Program
  ├── test_copy.sh # Shell script to test mycp
  ├── system_call_analysis.sh # Script to analyze system calls
  ├── file1.txt # File to be copied
```
## Design of ```mycp```
The design behind the utility is based on C system calls such as: ```(open, read, write, close)```
- Opening the source file for reading.
- Creating/Opening the destination file for writing.
- Reading data from the source file in chunks (using a buffer).
- Writing the read data to the destination file.
- Closing both files after the operation is complete.

## System Calls Used in ```mycp```:

- open() – to open files.
- read() – to read data from the source file.
- write() – to write data to the destination file.
- close() – to close the file descriptors.
## Files

- **file_ops.c / file_ops.h**: Functions for file operations (open, read, write, close).
- **mycp.c**: Main program implementing the copy logic.
- **Makefile**: Build making instructions and flags for the project.

## Building

```sh
  make
```

## Usage & Example

```sh
  ./mycp <source_file> <destination_file>

  ./mycp file1.txt file2.txt
```

## Test Script
```sh
  #give permissions
  chmod u+x test_copy.sh
  ./test_copy.sh
```

## System Call Analysis
```sh
  #give permissions
  chmod u+x system_call_analysis.sh
  ./system_call_analysis.sh
```

## System Call Analysis (In Depth)
1. Speed:
mycp is 4 times faster than cp because it uses less system calls (38 vs 101).

2. System Calls:

  cp does extra calls: Uses mmap for large files.

  mycp keeps it simple: Uses basic read/write for copying.

## Valgrind Memory Leak Checks
There were no issues with memory loss or leaks when tested through valgrind using ```valgrind --leak-check=full ./mycp -f
file1.txt file2.txt```.
This was the valgrind output:
```
==22655== Memcheck, a memory error detector
==22655== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==22655== Using Valgrind-3.23.0 and LibVEX; rerun with -h for copyright info
==22655== Command: ./mycp -f file1.txt file2.txt
==22655== 
==22655== 
==22655== HEAP SUMMARY:
==22655==     in use at exit: 0 bytes in 0 blocks
==22655==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==22655== 
==22655== All heap blocks were freed -- no leaks are possible
==22655== 
==22655== For lists of detected and suppressed errors, rerun with: -s
==22655== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```


