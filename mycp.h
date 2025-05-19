// --- INSTRUCTIONS FOR STUDENTS ---
// DO NOT MODIFY ANY OF THE EXISTING CODE IN THIS HEADER FILE.
// Detailed comments to each of the declared
// functions and structure are provided. 

#ifndef MYCP_H
#define MYCP_H

#include <stdio.h>
#include <string.h>
#include "file_ops.h"

/**
 * @brief A structure to hold settings for the file copying operation.
 *
 * @var force An integer flag. If non-zero, it indicates that existing
 * destination files should be overwritten without prompting.
 * If zero, the program might prompt the user or handle overwriting
 * differently.
 * @var preserve An integer flag. If non-zero, it indicates that file
 * metadata (such as permissions and timestamps) should be preserved
 * during the copy operation. If zero, the destination file will
 * likely have default metadata.
 */
typedef struct {
    int force;
    int preserve;
} CopySettings;


/**
 * @brief Copies the content of a source file to a destination file,
 * respecting the provided copy settings.
 *
 * @param src The path to the source file that will be copied.
 * This should be a valid file path that the program has read access to.
 * @param dest The path to the destination file where the content of the
 * source file will be written. If the file does not exist, it should
 * be created (permissions will depend on the implementation and potentially
 * the 'preserve' setting). If it exists, the behavior depends on the
 * 'force' setting.
 * @param settings A 'CopySettings' struct containing flags that modify the
 * copying behavior, such as whether to force overwriting and whether to
 * preserve file metadata.
 * @return 0 on successful completion of the copy operation, and a non-zero
 * value (typically -1) if an error occurs during the process (e.g.,
 * failure to open or read the source file, failure to open or write to
 * the destination file, or other system-level errors).
 *
 * @note **STUDENTS MUST NOT MODIFY THIS FUNCTION DECLARATION.**
 */
int copy_file(const char *src, const char *dest, CopySettings settings);


#endif
