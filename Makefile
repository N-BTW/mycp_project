CFLAGS = -Wall -Wextra -g
# Makefile for the 'mycp' program

# TODO: Define the command to create the final executable 'mycp'
# by linking the object files: main.o, mycp.o, and file_ops.o
# ROLE GOES HERE
mycp: main.o mycp.o file_ops.o	
# Command to link object files will go here
	gcc -o mycp main.o mycp.o file_ops.o

# TODO: Define the command to compile 'main.c' into an object file 'main.o'.
# ROLE GOES HERE
main.o: main.c
# Command to compile main.c will go here
	gcc $(CFLAGS) -c main.c

# TODO: Define the command to compile 'mycp.c' into an object file 'mycp.o'.
# ROLE GOES HERE
mycp.o: mycp.c
# Command to compile mycp.c will go here
	gcc $(CFLAGS) -c mycp.c

# TODO: Define the command to compile 'file_ops.c' into an object file 'file_ops.o'.
# ROLE GOES HERE
file_ops.o: file_ops.c
# Command to compile file_ops.c will go here
	gcc $(CFLAGS) -c file_ops.c

# TODO: Define the command to remove the generated object files and the 'mycp' executable.
clean:
	rm -f *.o mycp

# TODO: Define the command to run the test script 'test_copy.sh'.
test:
	./test_copy.sh
