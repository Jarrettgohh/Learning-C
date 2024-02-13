#include <stdio.h>
#include <string.h>

int main()
{

 typedef enum
 {
  J = 74,
  G = 71
 } ASCII;

 char dest[4];
 char *dest_ptr = &dest[0]; // not actually needed - dest_ptr can be directly represented by either &dest[0] or dest

 ASCII letter = G;

 size_t n = 2;

 char *res = memset(dest_ptr, letter, n);

 for (unsigned i = 0; i < n; i++)
 {

  printf("%c\n", res[i]);
 }

 return 0;
}