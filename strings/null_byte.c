#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// The null byte character (%00 in URL, 0x00 in hex, '\0' in C) also called null terminator, null character, is used in C/C++ to indicate the end of a string
//

void null_byte(char null_b)
{

 char str[20] = "jarrett goh";

 size_t sizeof_str = sizeof str;

 char *dest = (char *)malloc(sizeof_str);

 // for testing purposes - to simulate the memory being filled with random characters besides the null character
 for (unsigned i = 0; i < sizeof_str; ++i)
 {
  dest[i] = '0'; // fill in the memory with the char 0 (different from null character '\0')
 }

 size_t strlen_str = strlen(str);
 strncpy(dest, str, strlen_str);

 printf("Inserting byte: (char)%d into position %lu of the string...\n", null_b, strlen_str);
 dest[strlen_str] = null_b;

 printf("dest = %s\n", dest);
 printf("%lu\n\n", strlen(dest));
}

int main()
{

 char null_bytes[4] = {'\0', 0x0, 00, '\x0'}; // different representations of the null-byte character

 for (unsigned i = 0; i < sizeof null_bytes; ++i)
  null_byte(null_bytes[i]);

 return 0;
}