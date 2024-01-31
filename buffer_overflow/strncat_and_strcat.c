#include <stdio.h>
#include <string.h>

void exe_strncat()
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
}

void exe_strcat()
{
 char dest[10] = "012345678";
 char src[20] = "012345678AAAAAAAA";

 printf("%lu\n", strlen(dest));
 strcat(dest, src); // write more than the defined buffer for char string `dest`
 printf("%s\n", dest);
 printf("%lu\n", strlen(dest));
}

int main(void)
{

 // exe_strncat();
 exe_strcat();
}