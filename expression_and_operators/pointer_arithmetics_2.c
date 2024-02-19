#include <stdio.h>

int main()
{
 char str[] = "jarrett";
 char *p = str;

 printf("%c\n", p[1]);     // refers to the value of the second element itself
 printf("%p\n", p + 1);    // refers to the memory address of the second element
 printf("%c\n", *(p + 1)); // refers to the memory address of the second element

 return 0;
}