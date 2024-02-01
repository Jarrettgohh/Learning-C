#include <stdio.h>
#include <limits.h>

int main()
{

 unsigned int ui = UINT_MAX;
 signed int si = -1; // due to sign extension
 signed char c = -1;

 if (c == ui)
 {
  puts("-1 equals 4,294,967,295");
 }

 printf("%u\n", ui);
 printf("%u\n", c);  // signed variable as what its declared with before not able to store negative values, hence the wraparound
 printf("%u\n", si); // signed variable as what its declared with before not able to store negative values, hence the wraparound

 return 0;
}