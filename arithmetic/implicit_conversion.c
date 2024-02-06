#include <stdio.h>
#include <limits.h>

void sign_extension_example_1()
{
 unsigned int ui = UINT_MAX; // 32 bits -> -1 (0xFFFFFFFF) (-2^31 + (2^31 -1))
 signed int si = -1;
 signed char nc = -1; // 1111 11111 (0xFF); 8 bits -> -2^8 + (2^8 - 1)
 signed char c = 255; // 1111 11111 (0xFF); 8 bits -> 2^8 -1

 // unsigned ui converted to signed
 if (c == ui && nc == ui)
 {
  puts("signed -1 and 255 equals unsigned 4,294,967,295");
 }

 printf("%u\n", ui);
 printf("%u\n", c); // originally a signed variable that is not able to store negative values, hence the wraparound
 printf("%u\n", nc);
 printf("%u\n", si); // originally a signed variable that is not able to store negative values, hence the wraparound
}

void sign_extension_example_2()
{
 //
 // ** sign extension does not work for unsigned data types
 //

 signed int i = UINT_MAX; // 32 bits -> -1 (0xFFFFFFFF) (-2^31 + (2^31 -1))
 signed int im = INT_MAX; // 32 bits -> 2147483647 (0x7FFFFFFF) (2^31 -1)
 signed char uc = -1;     // 8 bits -> (0xFF)

 if (uc == i)
 {
  puts("signed -1 equals signed -1");
 }

 if (uc != im)
 {
  puts("signed -1 NOT equals signed 2147483647 (INT_MAX)");
 }
}

void unsigned_wraparound()
{

 signed int i = UINT_MAX;
 unsigned char c = -1; // wraparounds to 255 (0xFF?)
 signed int si_from_c = c;
 signed int si = -1;

 printf("signed int %hhi\n", c); // -1
 printf("%hhu\n", c);            // 255

 printf("new signed int declared with c: %d\n", si_from_c); // 255
 printf("new signed int declared with c: %u\n", si_from_c); // 255
 printf("new signed int declared with -1: %d\n", si);       // -1
 printf("new signed int declared with -1: %u\n", si);       // 4294967295
}

int main()
{

 sign_extension_example_1();
 sign_extension_example_2();
 unsigned_wraparound();

 return 0;
}