#include <stdio.h>
#include <string.h>

int main(void)
{

 //
 char q[10] = "jarrett";
 char t = 't';
 char *pT = &t;

 printf("%p\n", pT);
 strncat(q, pT, 1);
 printf("%s\n", q);

 //
 // ####
 //

 char y[10] = "jarrett";
 char x[50] = "goh";

 strncat(y, x, 3);
 printf("%s\n", y);

 //
 // ####
 //

 char n[10] = "jarrett";
 char m = 'g';

 strncat(n, &m, 1);

 printf("%p\n", &m);
 printf("%s\n", n);

 //
 // **** strcat() is less secure as it does not check the size - may cause buffer overflow
 // ==> strcat() does not check for the size of the copied data, and copies until it gets to a null terminator
 //

 // strcat()
}