#include <stdio.h>

int main()
{
 printf("%ld\n", __STDC_VERSION__);
 printf("%u\n", __STDC_UTF_16__);
 printf("%u\n", __STDC_UTF_32__);

 return 0;
}