#include <stdio.h>
#include <string.h>

int main(void)
{

 char y[10] = "jarrett";

 char x[3] = "goh";
 strncat(y, x, 1);

 // signed char m = 'g';
 // strncat(y, &x, 1);

 printf("%s\n", y);

 // printf("%c\n", y);
}