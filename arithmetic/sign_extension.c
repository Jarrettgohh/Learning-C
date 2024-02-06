#include <stdio.h>

// *sign extension* is used to convert a signed value to a larger-width object
// -> such a when a lower integer conversion rank data type compared to int or unsigned int (such as signed char) is promoted to an object of type signed int
// -> it is used to convert a signed value to a larger-width object
// -> the sign bit is copied into each position of the expanded object
//
// notes in sign_extension.txt

void example_1()
{
 printf("\n--------------------- %s ----------------------\n", "declaration as signed char - sign extended from char to int");

 //
 // ** max signed char range = 2^7 -1 = 127
 //

 // binary: 1111 1111, hex: 0xFF in memory
 signed char x = 255;
 // binary: 0100 0000, hex: 0x40 in memory
 signed char y = 64;
 // binary: 1110 1111, hex: 0xEF in memory
 signed char z = 239;

 printf("%s\n", "x:");
 printf("signed char: %hhi\n", x);
 printf("signed int: %d\n", x);
 printf("unsigned int: %u\n", x);
 printf("%lu bits\n\n", sizeof(x) * 8);

 printf("%s", "\n");

 printf("%s\n", "y:");
 printf("signed char: %hhi\n", y);
 printf("signed int: %d\n", y);
 printf("unsigned int: %u\n", y);
 printf("%lu bits\n\n", sizeof(y) * 8);

 printf("%s", "\n");

 printf("%s\n", "z:");
 printf("signed char: %hhi\n", z);
 printf("signed int: %d\n", z);
 printf("unsigned int: %u\n", z);
 printf("%lu bits\n\n", sizeof(z) * 8);

 printf("\n\n\n--------------------- %s ---------------------- \n", "declaration as signed int");
 signed int a = 255; // binary: 1111 1111 in memory (with extra 32-8=24 extra 0's bits preceding) as signed int has 32 bits
 signed int b = 64;  // binary: 0100 0000 (0x00000040) in memory (with extra 32-8=24 extra 0's bits preceding) as signed int has 32 bits
 signed int c = 239; // binary: 1110 1111 (0xFFFFFFEF) in memory (with extra 32-8=24 extra 0's bits preceding) as signed int has 32 bits

 printf("%s\n", "a:");
 printf("signed int: %d\n", a);
 printf("unsigned int: %u\n", a);
 printf("%lu bits\n\n", sizeof(a) * 8); // sizeof() returns in bytes

 printf("%s", "\n");

 printf("%s\n", "b:");
 printf("signed int: %d\n", b);
 printf("unsigned int: %u\n", b);
 printf("%lu bits\n\n", sizeof(b) * 8); // sizeof() returns in bytes

 printf("%s", "\n");

 printf("%s\n", "c:");
 printf("signed int: %d\n", c);
 printf("unsigned int: %u\n", c);
 printf("%lu bits\n\n", sizeof(c) * 8); // sizeof() returns in bytes
}

int main()
{
 example_1();
 return 0;
}