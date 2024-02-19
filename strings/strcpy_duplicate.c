#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcpy_duplicate(char *dest, const char *src)
{

 char *s = dest;

 while (*dest++ = *src++)
  ; // *(dest += 1) = *(src += 1) same as dest[i] = src[i] where i is incremented until src[i] evaluates to NULL - end of string; null-termination reached (assignment returns NULL)

 return s;
}

int main()
{

 char src[] = "jarrett";

 size_t src_len = sizeof src + 1; // extra 1 byte for null-terminator
 char *dest = (char *)malloc(src_len);

 char *s = strcpy_duplicate(dest, src);

 for (unsigned i = 0; i < src_len; ++i)
  printf("%c\n", s[i]);

 return 0;
}