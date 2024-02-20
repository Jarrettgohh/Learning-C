#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

 char str[] = "jarrett";
 size_t sizeof_str = sizeof str + 1;

 char *p = (char *)malloc(sizeof_str);

 strncpy(p, str, sizeof_str);

 printf("%c\n", *p); // prints first element of the string array

 return 0;
}