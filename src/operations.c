#include "operations.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_printable(char c) {
    return (c >= 32 && c <= 126);
}

void extract_strings(FILE *fp, const char *filename) {
    unsigned char buffer[BUFFER_SIZE];
    char string[BUFFER_SIZE];
    int index = 0;
    
    while (!feof(file)) {
        int bytesRead = fread(buffer, 1, BUFFER_SIZE, file);
        for (int i = 0; i < bytesRead; i++) {
            if (is_printable(buffer[i])) {
                string[index++] = buffer[i];
                if (index >= BUFFER_SIZE - 1) {
                    index = 0;  
                }
            } else {
                if (index >= MIN_STRING_LENGTH) {
                    string[index] = '\0';
                    printf("%s\n", string);
                }
                index = 0;
            }
        }
    }

    fclose(file);
}

