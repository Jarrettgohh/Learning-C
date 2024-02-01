#include <stdio.h>

int main()
{
 int si = 5;
 short ss = 8;

 long sl = (long)si; // cast variable si to the type long int - as long int is a larger int type than short, it is guaranteed to be safe

 unsigned short us = (unsigned short)(ss + sl); // cast the sum of ss and sl to unsigned short - as the cast conversion is to an unsigned type, the value might not be accurate

 return 0;
}