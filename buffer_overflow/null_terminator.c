#include <stdio.h>
#include <string.h>

// ======================================
// In theory from what I understand, C identify the length of strings from the null terminator - so if the null terminator is not specified, it might possibly allow reading into more memory than specified originally
// ======================================
// 1. An example would be to declare a string variable with a specified size, and declare or copy a string with equal length to the variable - this causes the null terminator to not be defined
//
// char a[16];
// strncpy(a, "0123456789abcdef", sizeof(a));
// printf("%lu", strlen(a)); // will not return `16` but rather an arbitary value until the compiler encounters a null terminator (\0)
//

void test(void)
{
 char a[20] = "jarrett";
 strncpy(a, "0123456789abcdef", sizeof(a));

 printf("%s\n", a);

 return;
}

void do_something_with_a(char *a)
{
 int a_len = 0;
 char new_array[16];

 a_len = strlen(a);
 printf("%d\n", a_len);

 // printf("%s\n", a);
 // printf("%lu\n", sizeof(a));

 int a_len_less_1 = a_len - 1;

 // for (int i = 15; i <= a_len_less_1; ++i)
 // {
 //  printf("%s\n", "------------");
 //  printf("%d\n", i);
 //  printf("%c\n\n", a[i]);
 //  printf("%s\n", "------------");
 // }

 // char start = a[15];
 // char end = a[str_len_less_1];

 // printf("%c\n", start);
 // printf("%c\n", end);

 // Gonna munge the 'a' string, so lets copy it first into new_array
 strncpy(new_array, a, a_len);
}

int main()
{

 char a[16];

 strncpy(a, "0123456789abcdef", sizeof(a));

 // printf("%c\n", a[17]);

 int i = 22;
 do
 {

  char *b = &a[i];
  // printf("%c\n", *b);

  if (!*b)
  {
   printf("%s\n", "-------------------");
   printf("%s\n", "NULL byte encountered");
   printf("%d\n", i);

   *b = 'j';
  }

  printf("%c\n", a[i]);
  printf("%s\n", "-------------------");

  i++;

 } while (i <= 26);

 int a_len = strlen(a);
 printf("%d\n", a_len);

 printf("%d\n", a[22]);
 return 0;

 // do_something_with_a(a);
}
