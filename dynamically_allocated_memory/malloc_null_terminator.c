#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comparison()
{
 // '\0' represents the NULL character - the decimal value of 0 (zero)
 printf("%d\n", '\0' == 0);   // 1: true
 printf("%d\n", '\0' == '0'); // 0: false
 printf("%d\n", '\1' == 1);   // 1: true
 printf("%d\n", '\1' == '1'); // 0: false
}

// for gcc c17, it seems that the memory will be filled with null character automatically, or strncpy() function automatically includes it
void proper_null_termination_example()
{

 unsigned malloc_size = 16;
 char *str = (char *)malloc(malloc_size);

 if (str)
 {

  strncpy(str, "123456789abcdef", 15);

  printf("str = %s\n", str);
  printf("%lu\n", strlen(str));

  free(str);
 }
}

void proper_null_termination_example1()
{

 unsigned malloc_size = 16;
 char *str = (char *)malloc(malloc_size);

 for (unsigned i = 0; i < malloc_size; ++i)
 {
  str[i] = '0'; // fill in the memory with the char 0 (different from null character '\0')
 }

 if (str)
 {

  // if instead a higher value of chars is used to read from the source string, the null-terminator will be included OR if the source string has lower length than the value of chars to read
  strncpy(str, "123456789abcde", 15); // will be properly null-terminated

  printf("str = %s\n", str);
  printf("%lu\n", strlen(str));

  free(str);
 }
}

void proper_null_termination_example2()

{
 unsigned malloc_size = 16;
 char *str = (char *)malloc(malloc_size);

 for (unsigned i = 0; i < malloc_size; ++i)
 {
  str[i] = '0'; // fill in the memory with the char 0 (different from null character '\0')
 }

 if (str)
 {

  strncpy(str, "123456789abcdef", 15);
  str[15] = '\0'; // explicitly null-terminate

  // the resulting string will not be properly null terminated and be filled with char zeros
  printf("str = %s\n", str);
  printf("%lu\n", strlen(str));

  free(str);
 }
}

// there will be issues if the memory is filled with non null character ('\0') values, which causes the string to not be null-terminated
void wrong_null_termination_example1()
{
 unsigned malloc_size = 16;
 char *str = (char *)malloc(malloc_size);

 for (unsigned i = 0; i < malloc_size; ++i)
 {
  str[i] = '0'; // fill in the memory with the char 0 (different from null character '\0')
 }

 if (str)
 {

  // copy 12 chars from a string of length 15 - not properly null terminated as there is no space for the strncpy function to insert a '\0'
  strncpy(str, "123456789abcdef", 12);

  // // if instead a higher value of chars is used to read from the source string, the null-terminator will be included or if the source string has lower length than the value of chars to read - proper_null_termination_example1()
  // strncpy(str, "123456789abcde", 15); // will be properly null-terminated

  // the resulting string will not be properly null terminated and be filled with char zeros
  printf("str = %s\n", str);
  printf("%lu\n", strlen(str));

  free(str);
 }
}

void wrong_null_termination_example2()
{

 unsigned malloc_size = 16;
 char *str = (char *)malloc(malloc_size);

 for (unsigned i = 0; i < malloc_size; ++i)
 {
  str[i] = '`'; // similar to example 1, the string copied will not be null-terminated
  // printf("%d\n", (int)str[i]);
 }

 if (str)
 {
  strncpy(str, "123456789abcdef", 15);
  printf("str = %s\n", str);

  printf("%lu\n", strlen(str));
  free(str);
 }
}

int main()
{

 comparison();
 printf("\n");

 proper_null_termination_example();
 // proper_null_termination_example1();
 // proper_null_termination_example2();

 // wrong_null_termination_example1();
 // wrong_null_termination_example2();

 return 0;
}