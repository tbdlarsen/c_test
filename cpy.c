#include <stdio.h>
#include <string.h>


void* cpy(void* destination, const void* source, size_t n){
    unsigned char *d = destination;
    const unsigned char *s = source;

    while(n--){
        *d++ = *s++;
    }

    return destination;
}
