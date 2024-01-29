#include <stdio.h>
#include <string.h>

// ======================================
// In theory from what I understand, C identify the length of strings from the null terminator - so if the null terminator is not specified, it might possibly allow reading into more memory than specified originally
// ======================================

void do_something_with_a(char *a)
{
 int a_len = 0;
 char new_array[16];

 a_len = strlen(a);
 // printf("%lu\n", strlen(a));

 printf("%s\n", a);
 printf("%lu\n", sizeof(a));

 char start = a[13];
 char end = a[20];

 // printf("%c\n", start);
 // printf("%c\n", end);

 // Gonna munge the 'a' string, so lets copy it first into new_array
 strncpy(new_array, a, a_len);
}

int main()
{

 char a[16];

 printf("%lu\n", sizeof(a));

 strncpy(a, "0123456789abcde", sizeof(a));

 printf("%lu\n", sizeof(a));

 // printf("%c\n", a[17]);

 do_something_with_a(a);

 return 0;
}
