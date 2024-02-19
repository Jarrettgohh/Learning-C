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

void memory_storage()
{

 //
 // for gcc c17, malloc() initializes the dynamically allocated memory storage with null character when cast to char *
 //

 unsigned malloc_size = 16;
 char *str = (char *)malloc(malloc_size);

 for (unsigned i = 0; i < malloc_size; ++i)
 {

  printf("comparison with hex: %d\n", str[i] == 0x0);             // comparison with hex: 1 (true)
  printf("comparison with octal: %d\n", str[i] == 00);            // comparison with octal: 1 (true)
  printf("comparison with NULL character: %d\n", str[i] == '\0'); // comparison with NULL character: 1 (true)
  printf("comparison with decimal 0: %d\n", str[i] == '\0');      // comparison with decimal 0: 1 (true)
  printf("\n");
 }
}

void proper_null_termination_example()
{

 unsigned malloc_size = 16;
 char *str = (char *)malloc(malloc_size);

 // for testing purposes - to simulate the memory being filled with random characters besides the null character
 for (unsigned i = 0; i < malloc_size; ++i)
 {
  str[i] = '0'; // fill in the memory with the char 0 (different from null character '\0')
 }

 if (str)
 {

  strncpy(str, "123456789abcdef", 15);
  str[15] = '\0'; // explicitly null-terminate

  printf("str = %s\n", str);
  printf("%lu\n", strlen(str));

  free(str);
 }
}

void wrong_null_termination_example1()
{

 //
 // potentially wrong if the strncpy() function does not explicitly insert a null-character
 //

 unsigned malloc_size = 16;
 char *str = (char *)malloc(malloc_size);

 for (unsigned i = 0; i < malloc_size; ++i)
 {
  str[i] = '0'; // fill in the memory with the char 0 (different from null character '\0')
 }

 if (str)
 {

  // if instead a higher value of chars is used to read from the source string, the null-terminator will be included OR if the source string has lower length than the value of chars to read
  strncpy(str, "123456789abcde", 15); // might not always be properly null-terminated as the strncpy() function might not always insert a null-character

  printf("str = %s\n", str);
  printf("%lu\n", strlen(str));

  free(str);
 }
}

// there will be issues if the memory is filled with non null character ('\0') values, which causes the string to not be null-terminated
void wrong_null_termination_example2()
{

 //
 // wrong null-termination as the length to be read is lower than the source string passed in - assumes that the allocated storage already contains the null-termination character '\0'
 //
 // will not be properly null-terminated if the allocated storage does not contain the null-termination character by default
 //

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

  // // if instead a higher value of chars is used to read from the source string, the null-terminator will be included or if the source string has lower length than the value of chars to read - null_termination_example1()
  // strncpy(str, "123456789abcde", 15); // will be properly null-terminated

  // the resulting string will not be properly null terminated and be filled with char zeros
  printf("str = %s\n", str);
  printf("%lu\n", strlen(str));

  free(str);
 }
}

void wrong_null_termination_example3()
{

 ///
 // same issue as wrong_null_termination_example2()
 //

 unsigned malloc_size = 15;
 char *str = (char *)malloc(malloc_size);

 for (unsigned i = 0; i < malloc_size; ++i)
 {
  str[i] = '`'; // similar to example 1, the string copied will not be null-terminated
  // printf("%d\n", (int)str[i]);
 }

 if (str)
 {
  strncpy(str, "123456789abcdef", malloc_size); // might not always be properly null-terminated as the memory might not be explicitly filled with null characters

  printf("str = %s\n", str);
  printf("%lu\n", strlen(str));
  // free(str);
 }
}

int main()
{

 // comparison();
 memory_storage();
 printf("\n");

 // proper_null_termination_example();

 // wrong_null_termination_example1();
 // wrong_null_termination_example2();
 // wrong_null_termination_example3();

 return 0;
}