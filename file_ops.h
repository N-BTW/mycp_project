// --- INSTRUCTIONS FOR STUDENTS ---
// DO NOT MODIFY ANY OF THE EXISTING CODE IN THIS HEADER FILE.
// Detailed comments to each of the declared
// functions are provided. 


#ifndef FILE_OPS_H
#define FILE_OPS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * @brief Opens a file with specified flags and permissions.
 *
 * @param filename The path to the file to be opened.
 * @param flags    Flags specifying the access mode (e.g., O_RDONLY for reading).
 * Refer to the 'fcntl.h' header for possible flags.
 * @param mode     File permissions to set if the file is created (only used with O_CREAT).
 * This argument is of type 'mode_t' (defined in 'sys/stat.h').
 * @return         A non-negative file descriptor on success, -1 on failure.
 *
 * @note           **STUDENTS MUST NOT MODIFY THIS FUNCTION.**
 */
int open_file(const char *filename, int flags, mode_t mode);

/**
 * @brief Reads a specified number of bytes from a file descriptor into a buffer.
 *
 * @param fd     The file descriptor to read from.
 * @param buffer A pointer to the buffer where the read data will be stored.
 * @param count  The maximum number of bytes to read.
 * @return       The number of bytes actually read on success, 0 if end-of-file is reached, and -1 on error.
 *
 * @note           **STUDENTS MUST NOT MODIFY THIS FUNCTION.**
 */
ssize_t read_file(int fd, void *buffer, size_t count);

/**
 * @brief Writes a specified number of bytes from a buffer to a file descriptor.
 *
 * @param fd     The file descriptor to write to.
 * @param buffer A pointer to the buffer containing the data to be written.
 * @param count  The number of bytes to write.
 * @return       The number of bytes written on success, and -1 on error.
 *
 * @note           **STUDENTS MUST NOT MODIFY THIS FUNCTION.**
 */
ssize_t write_file(int fd, const void *buffer, size_t count);


/**
 * @brief Closes an open file descriptor.
 *
 * @param fd The file descriptor to close.
 * @return   0 on success, -1 on failure.
 *
 * @note           **STUDENTS MUST NOT MODIFY THIS FUNCTION.**
 */
int close_file(int fd);

/**
 * @brief Checks if a file exists.
 *
 * @param filename The path to the file to check.
 * @return         1 if the file exists, 0 otherwise.
 *
 * @note           **STUDENTS MUST NOT MODIFY THIS FUNCTION.**
 */
int file_exists(const char *filename);

#endif
