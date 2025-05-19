#include <fcntl.h> // Required for file control options (like O_RDONLY, O_WRONLY, O_CREAT)
#include <unistd.h> // Provides access to POSIX operating system API (like read, write, close)
#include <stdio.h>  // Standard input/output library (like perror)
#include <sys/stat.h> // Defines file status constants (like mode_t)
#include "file_ops.h" // this header file declares the function prototypes


/**
 * @brief Opens a file with specified flags and permissions.
 *
 * @param filename The path to the file to be opened.
 * @param flags    Flags specifying the access mode (e.g., O_RDONLY for reading).
 * Refer to the 'fcntl.h' header for possible flags.
 * @param mode     File permissions to set if the file is created (only used with O_CREAT).
 * @return         A non-negative file descriptor on success, -1 on failure.
 *
 * @details        This function uses the 'open()' system call to open or create a file.
 * If the 'open()' call fails, it prints an error message to stderr using 'perror()'.
 *
 */
int open_file(const char *filename, int flags, mode_t mode) {
    int fd = open(filename, flags, mode); //open file
    if (fd < 0) //if -1 return error
    {
    	perror("open_file: failed to open file");
    }
    return fd;
}


/**
 * @brief Reads a specified number of bytes from a file descriptor into a buffer.
 *
 * @param fd     The file descriptor to read from.
 * @param buffer A pointer to the buffer where the read data will be stored.
 * @param count  The maximum number of bytes to read.
 * @return       The number of bytes actually read on success (which can be less than 'count'),
 * 0 if end-of-file is reached, and -1 on error.
 *
 * @details      This function uses the 'read()' system call to read data from the file.
 * It's important to handle the case where fewer bytes are read than requested.
 * If the 'read()' call fails, it prints an error message using 'perror()'.
 *
 */

ssize_t read_file(int fd, void *buffer, size_t count) {
    ssize_t bytes_read = read(fd, buffer, count); //read file
    if (bytes_read < 0) //if fewer bytes are read than requested
    {
    	perror("read_file: failed to read file");
    }
    return bytes_read;
}

/**
 * @brief Writes a specified number of bytes from a buffer to a file descriptor.
 *
 * @param fd     The file descriptor to write to.
 * @param buffer A pointer to the buffer containing the data to be written.
 * @param count  The number of bytes to write.
 * @return       The number of bytes actually written on success, and -1 on error.
 *
 * @details      This function uses the 'write()' system call to write data to the file.
 * If the 'write()' call fails, it prints an error message using 'perror()'.
 *
 */
ssize_t write_file(int fd, const void *buffer, size_t count) {
    const char *buffer_pointer = buffer;
    size_t bytes_count = count;
    while (bytes_count > 0)
    {
    	ssize_t bytes_written = write(fd, buffer_pointer, bytes_count); //write data
    	if (bytes_written < 0) //if error occurs exit with -1
    	{
    	    perror("write_file: write error");
    	    return -1;
    	}
    	buffer_pointer = buffer_pointer + bytes_written; //iterate pointer
    	bytes_count = bytes_count - bytes_written; //decrease count
    }
    return (ssize_t)count;
}

/**
 * @brief Closes an open file descriptor.
 *
 * @param fd The file descriptor to close.
 * @return   0 on success, -1 on failure.
 *
 * @details  This function uses the 'close()' system call to release the resources associated
 * with the open file descriptor. It's important to close file descriptors when
 * If the 'close()' call fails, it prints an error message using 'perror()'.
 *
 */
int close_file(int fd) {
    if (close(fd) < 0) // if error occurs exit with -1
    {
    	perror("close_file: close error");
    	return -1;
    }
    return 0;
}


/**
 * @brief Checks if a file exists.
 *
 * @param filename The path to the file to check.
 * @return         1 if the file exists, 0 otherwise.
 *
 * @details        This function uses the 'access()' system call to check the accessibility
 * of the file. Specifically, it checks for the existence of the file (F_OK).
 *
 */

int file_exists(const char *filename) {
    int exist = access(filename, F_OK); //access file
    if (exist == 0) {return 1;} //if it exists exit with 1
    else {return 0;} //otherwise exit with 0
}
