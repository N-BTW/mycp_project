// --- INSTRUCTIONS FOR STUDENTS ---
// DO NOT MODIFY ANY OF THE EXISTING CODE IN THIS SOURCE FILE ('mycp.c').
// Your task is ONLY to complete the implementation of the 'copy_file' function.

// STEP 1: Include the necessary header file.
// You MUST include the 'mycp.h' header file at the beginning of this file.
// This header file contains the declaration of the 'copy_file' function
// and the definition of the 'CopySettings' struct.

// header file GOES HERE 

#include "mycp.h"

// You are NOT required to include any other standard library headers for this task.
// The necessary file operation functions ('open_file', 'read_file', 'write_file',
// 'close_file', 'file_exists') are available from a separate
// compilation units (header files) that will be linked with your code.


/****************************************************************************************************/

/**
 * @brief Copies the content of a source file to a destination file,
 * with respect to the provided copy settings.
 *
 * @param src The path to the source file that will be copied.
 * @param dest The path to the destination file where the content of the
 * source file will be written.
 * @param settings A 'CopySettings' struct containing flags that modify the
 * copying behavior.
 * @return 0 on successful completion, -1 on error.
 *
 * @note **STUDENTS MUST IMPLEMENT THE BODY OF THIS FUNCTION.**
 */
int copy_file(const char *src, const char *dest, CopySettings settings) {
    // STEP 2: Check if the destination file exists and the 'force' flag is not set.
    // If the destination file exists and the 'settings.force' member is 0 (false),
    // you should print an error message "Destination file exists. Use -f to force overwrite.\n"
    // to stderr indicating that the destination
    // file exists and instruct the user to use the '-f' option to force overwriting.
    // After printing the message, return -1 to indicate failure.
    
    
    // CODE GOES HERE
    if (file_exists(dest) && settings.force == 0) {
        fprintf(stderr, "Destination file exists. Use -f to force overwrite.\n");
        return -1;
    }
    /****************************************************************************************************/
    
    // STEP 3: Open the source file for reading.
    // Use the 'open_file' function (declared in 'mycp.h' and assumed to be
    // implemented elsewhere) to open the source file specified by the 'src'
    // path in read-only mode (O_RDONLY). The mode argument for 'open_file'
    // in this case should be 0.
    // Store the returned file descriptor in an integer variable (e.g., 'src_fd').
    // If 'open_file' returns a value less than 0, it indicates an error.
    // In this case, you should return -1.

    // CODE GOES HERE
    int src_fd = open_file(src, O_RDONLY, 0);
    if (src_fd < 0) {
        return -1;
    }
    /****************************************************************************************************/
    

    // STEP 4: Open the destination file for writing.
    // Use the 'open_file' function to open the destination file specified by
    // the 'dest' path. You need to open it in write-only mode (O_WRONLY).
    // If the destination file does not exist, it should be created (O_CREAT).
    // If it exists, its content should be truncated (O_TRUNC) to overwrite it.
    // The mode argument for creating the file should be 0644 (read/write for owner,
    // read for group and others).
    // Store the returned file descriptor in an integer variable (e.g., 'dest_fd').
    // If 'open_file' returns a value less than 0, it indicates an error.
    // In this case, you must first close the source file descriptor (using
    // 'close_file(src_fd)') and then return -1.


    // CODE GOES HERE
    int dest_fd = open_file(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        close_file(src_fd);
        return -1;
    }
    /****************************************************************************************************/
    

    // STEP 5: Read from the source file and write to the destination file in a loop.
    // Declare a buffer (e.g., a character array named 'buffer') of a reasonable size
    // (e.g., 1024 bytes).
    // Use the 'read_file' function to read data from the source file descriptor
    // ('src_fd') into the 'buffer'. The number of bytes to read should be the size
    // of the buffer.
    // The 'read_file' function returns the number of bytes actually read. The loop
    // should continue as long as 'read_file' returns a value greater than 0.
    
    char buffer[1024];
    ssize_t bytes_read;

    while ((bytes_read = read_file(src_fd, buffer, sizeof(buffer))) > 0) {
    
        // STEP 6: Loop's body... Write the read data to the destination file.
        // Inside the loop, use the 'write_file' function to write the data from the
        // 'buffer' to the destination file descriptor ('dest_fd'). The number of
        // bytes to write should be the value returned by 'read_file' in the current
        // iteration ('bytes_read').
        // If 'write_file' returns a value less than 0, it indicates an error during
        // writing. In this case, you must close both the source and destination
        // file descriptors (using 'close_file(src_fd)' and 'close_file(dest_fd)')
        // and then return -1.
        // CODE GOES HERE
    if (write_file(dest_fd, buffer, bytes_read) < 0) {
            close_file(src_fd);
            close_file(dest_fd);
            return -1;
        }
    }

    

    // STEP 7: Close the file descriptors.
    // After the loop finishes (when 'read_file' returns 0, indicating the end of
    // the source file), you need to close both the source and destination file
    // descriptors using the 'close_file' function.
    // CODE GOES HERE
    close_file(src_fd);
    close_file(dest_fd);


    // If all operations are successful, the function should return 0.
    return 0;
}
