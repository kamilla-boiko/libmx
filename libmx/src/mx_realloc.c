#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int mx_strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

char *mx_strnew(const int size) {
   if (size < 0) {
       return NULL;
   }
   char *s = (char *)malloc(size + 1);
   for(int i = 0; i < size + 1; i++) {
       s[i] = '\0';
   }
   return s;
}

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;
    int j = 0;
    while(i != len) {
        if (src[j] != '\0') {
            dst[i] = src[j];
            i++;
            j++;
        }
        else {
            dst[i] = '\0';  
            i++;
        }
    }
    return dst;
}

char *mx_strndup(const char *s1, size_t n) {
    char *s = mx_strncpy(mx_strnew(mx_strlen(s1)), s1, n);
    return s;
}

void mx_strdel(char **str) {
    free(str);
    str = NULL;
}

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    for (int i = 0; i <= len2; i++) {
        s1[len1] = s2[i];
        len1++;
    }
    return s1;
}

void *mx_realloc(void *ptr, size_t size) {
    unsigned char *new_ptr = ptr;
    //unsigned int i = 0;
    //while (i < size) {
        *new_ptr = mx_strndup(ptr, size);
        //i++;
   // }
    mx_strdel(ptr);
    return new_ptr;
}

int main() {
  char *ptr = (char *) malloc(24);
  ptr = "Follow the white rabbit";
  realloc(ptr, 25);
  mx_strcat(ptr, ".");
 // printf("%s\n", mx_realloc(ptr, 25));
  printf("%s\n", ptr);
  return 0;
}
