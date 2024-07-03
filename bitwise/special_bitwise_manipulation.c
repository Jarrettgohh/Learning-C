#include <stdio.h>

//
// Making arithmetic operations just by manipulating the bitwise of an integer without using special arithmetic operators
//

// multiply an unsigned integer by 2 without using the * operator
// bitwise left shift alone is enough to perform this operation
unsigned multiply_two(unsigned i)
{

 unsigned x = i << 1;
 return x;
}

// divide an unsigned integer by 2 without using the / operator
// bitwise right shift alone is enough to perform this operation
unsigned divide_two(unsigned i)
{

 unsigned x = i >> 1;
 return x;
}

int main()
{

 printf("%u\n", multiply_two(2));
 printf("%u\n", multiply_two(4));
 printf("%u\n", multiply_two(22));
 printf("%u\n", multiply_two(40));

 printf("\n");

 printf("%u\n", divide_two(2));
 printf("%u\n", divide_two(4));
 printf("%u\n", divide_two(22));
 printf("%u\n", divide_two(40));

 return 0;
}