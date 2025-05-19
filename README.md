# mycp_project

A simple file copy utility implemented in C using system calls.

## Project Structure

```
mycp_project/
├── file_ops.c
├── file_ops.h
├── mycp.c
├── Makefile
└── README.md
```

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
