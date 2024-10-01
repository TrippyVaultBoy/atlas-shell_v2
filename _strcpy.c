#include "main.h"

char *_strcpy(char *dest, const char *src) {
    char *original_dest = dest;

    while ((*dest++ = *src++) != '\0') {
        ;
    }

    return original_dest;
}