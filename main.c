// --- INSTRUCTIONS FOR STUDENTS ---
// DO NOT MODIFY ANY OF THE EXISTING CODE IN THIS SOURCE FILE ('main.c').
// Your task is ONLY to complete the program by adding the necessary
// include directive at the beginning of this file.

// STEP 1: Include the necessary header file.
// You MUST include the 'mycp.h' header file at the beginning of this file.
// This header file contains the declarations of the functions you will be using,
// such as 'copy_file' and the definition of the 'CopySettings' struct.

// header GOES HERE
#include "mycp.h"

// You are NOT required to include any other standard library headers for this task.

// This function prints the usage instructions for the 'mycp' program.
void print_usage(const char *prog_name) {
    // CODE GOES HERE
    fprintf(stderr, "Usage: %s [-f] [-p] source destination\n", prog_name);
}

// The main function of the 'mycp' program. It parses command-line arguments
// and calls the 'copy_file' function.
int main(int argc, char *argv[]) {
    // Check if the number of command-line arguments is less than 3 (program name,
    // source file, and destination file). If so, print the usage instructions and
    // exit with an error code (1).
    //CODE GOES HERE
    if (argc < 3) {
        print_usage(argv[0]);
        return 1;
    }

    // Initialize a 'CopySettings' struct with default values (force = 0, preserve = 0).
    //CODE GOES HERE
    CopySettings settings = {0, 0};

    // Initialize pointers to store the source and destination file paths.
    //CODE GOES HERE
    const char *src = NULL;
    const char *dest = NULL;
    
    
    // Loop or Iterate through the command-line arguments starting from the second argument (index 1).
    for (int i = 1; i < argc; i++) {

        // Check if the current argument is "-f". If so, set the 'force' flag in the
        // 'settings' struct to 1.
        if (strcmp(argv[i], "-f") == 0) {
            settings.force = 1;
        }
  
  
        // Check if the current argument is "-p". If so, set the 'preserve' flag in the
        // 'settings' struct to 1.
        else if (strcmp(argv[i], "-p") == 0) {
            settings.preserve = 1;
        }
        
        // If 'src' is NULL, it means we haven't encountered the source file argument yet.
        // Assign the current argument to 'src'.
        else {
            if (!src) {
                src = argv[i];
            }
        
        // If 'src' is not NULL and 'dest' is NULL, it means we've found the source file
        // argument, and the current argument must be the destination file. Assign the
        // current argument to 'dest'.
        //LOOP CODE GOES HERE
            else {
                dest = argv[i];
            }
        }
    }

    // After parsing the arguments, check if both 'src' and 'dest' have been assigned
    // a value. If either is still NULL, it means the user didn't provide both the
    // source and destination files. In this case, print the usage instructions and
    // exit with an error code (1).
    //CODE GOES HERE
    if (!src || !dest) {
        print_usage(argv[0]);
        return 1;
    }

    // Validate the existence of the source file
    if (!file_exists(src)) {
        fprintf(stderr, "Error: Source file '%s' does not exist.\n", src);
        return 1;
    }

    // Finally, call the 'copy_file' function (declared in 'mycp.h' and implemented
    // in 'mycp.c') with the parsed source file path, destination file path, and
    // the 'settings' struct. The return value of 'copy_file' (0 for success, -1 for
    // error) is returned as the exit status of the 'main' function.
    //CODE GOES HERE
    return copy_file(src, dest, settings);
}

// --- END OF INSTRUCTIONS ---