#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *d = dst;
    const unsigned char *s = src;
    unsigned int i = 0;
    while(i < len) {
        *d++ = *s++;
        i++;
    }
    return dst;
}
