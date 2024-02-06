#include <stdio.h>
#include <limits.h>
#include <math.h>

#define Abs(i) (i < 0 ? -i : i)

//
// ** The signed integer overflow vulnerability does not directly cause a buffer overflow; the vulnerability is not that the buffer will be directly overwritten with the input data, but rather that signed integer overflow can cause a silent wrapping of the value (similar to unsigned integer wraparound (?)) or throw an error
// -> however, if the silent wrap occurs, the resulting integer value can be negative or postive but way larger than expected - causing a possible buffer overflow if this value is used to access memory in another way
//

void example()
{

 int l;   // 32 bit
 short s; // 16 bit
 char c;  // 8 bit

 l = 0xdeadbeef;
 // truncated to 0xbeef - sign extension to 0xffffbeef (1111 1111 1111 1111 1011 1110 1110 1111)
 s = l;
 // truncated to 0xef - sign extension to 0xfffffffef (1111 1111 1111 1111 1111 1111 1110 1111)
 c = l;

 printf("l = 0x%x, %d (%lu bits)\n", l, l, sizeof(l) * 8);
 printf("s = 0x%x, %d (%lu bits)\n", s, s, sizeof(s) * 8);
 printf("c = 0x%x, %d (%lu bits)\n", c, c, sizeof(c) * 8);
}

void abs_no_overflow()
{
 signed int a = -25;
 signed int abs_a = Abs(a); // pass in negative value (that is within the positive signed range) - returns absolute value

 printf("%d\n", abs_a);
}

void abs_overflow()
{
 signed int a = INT_MIN; // minimum int value which has a larger absolute value that the maximum positive range
 signed int abs_a = Abs(a);

 printf("%d\n", abs_a);
}

void example_2()
{

 signed int i = 2147483647;  // hex for supplied value: 0x7FFFFFFF (signed output: 2147483647)
 signed int x = 4294967295;  // hex for supplied value (2^32 - 1): 0xFFFFFFFF (signed output: -1)
 signed int b = -2147483648; // hex for supplied value: 0x80000000 (signed output: -2147483648)
 signed int y = 4294967294;  // hex for supplied value: 0xFFFFFFFE (signed output: -2)

 // // supplied value (2^32 + 10 = 4294967296 + 10), supplied decimal value higher than 0xFFFFFFFF (signed output: 10)
 // signed int m = 4294967296 + 10;

 // // supplied value (-2^31 - 1 = -2147483648 - 1), signed output: 2147483647
 // signed int l = -2147483648 - 1;

 printf("%d\n", i);
 printf("%d\n", x);
 printf("%d\n", b);
 printf("%d\n", y);
 // printf("%d\n", m);
 // printf("%d\n", l);
}

int main()
{

 // example();
 // abs_no_overflow();
 // abs_overflow();
 example_2();

 return 0;
}