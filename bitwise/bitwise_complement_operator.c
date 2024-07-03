#include <stdio.h>
#include <limits.h>

int main()
{

 unsigned char uc = UCHAR_MAX; // 0xFF

 // unsigned char uc gets converted to signed int and zero-extended to 0x000000FF and complmemented, making it become a negative value
 // unsigned 0xFF -> signed 0x000000FF -> signed 0xFFFFFF00 (-256)
 signed int i = ~uc;
 printf("%d\n", i);

 unsigned short us = USHRT_MAX; // 0xFFFF

 // unsigned short us gets converted to signed int and zero-extended to 0x0000FFFF and complemented, making it become a negative value
 // unsigned 0xFFFF -> signed 0x0000FFFF -> signed 0xFFFF0000 (-65536)
 signed int x = ~us;
 printf("%d\n", x);

 return 0;
}