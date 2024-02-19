#include <stdio.h>
#include <string.h>

int main()
{

 char str[] = "jarrett";
 char *p = str;

 *++p = 'g'; // same as *(++p) = 'g'; and the line below due to the prefix ++ and unary * operator having same precedence and right associativity, thus group from right - however causes side effect where p is increment
 // *(p += 1) = 'g'; // same - however causes side effect where p is incremented
 // p[1] = 'g'; // same

 for (unsigned i = 0; i < strlen(str); i++)
 {
  printf("\n");
  printf("Value referenced by p[i]: %c\n", p[i]); // *(p + 1 + i) - due to previous side-effect where p is incremented (++p)
  printf("Value referenced by str[i]: %c\n", str[i]);
 }

 return 0;
}