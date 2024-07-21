#ifndef LDH_CIO_H
#define LDH_CIO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BufferData
{
    char* data;
    size_t size;

} BufferData;

/**
 * Get the size of a file in bytes.
 *
 * @param FILE* fp
 *
 * @return int
 */
size_t GetFileSize(FILE* fp);

/**
 * Read the contents of a file and store it in memory.
 *
 * @param const char* toml_file    The name of the .toml file
 *
 * @return const char*
 */
const char* ReadFile(const char* toml_file);

/**
 * Read the contents of a file into BufferData struct. 
 *
 * @param const char* toml_file    The name of the .toml file
 *
 * @return BufferData*
 */
struct BufferData* ReadFileIntoBuffer(const char* toml_file);

/**
 * Free all of the memory associated with the buffer.
 *
 * @param struct BufferData* buffer.
 *
 * @return void
 */
void DestroyBufferData(struct BufferData* buffer);


#endif // !LDH_CIO_H
