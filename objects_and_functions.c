#include <stdio.h>

// ** NOTES **

// == OBJECT AND FUNCTION TYPES ==
// every type in C is either an object or function type
// eg. of object type is variable (int, float, etc...)
// eg. of function type is function - therefore functions are not objects, but do have types

// == SIGNED AND UNSIGNED ==
// signed data type can store positive and negative values - signed char range of value is -128 to 127
// unsigned data type can only store positive values - unsigned char range of value is 0 to 255
// --> since 1 byte of char can store 256 different values

void swap(int a, int b)
{ // function definition
}

int main(void)
{

 signed char signed_char = '`';
 unsigned char unsigned_char = '`';

 // char a[10] = "2560";
 // int b = 17;

 printf("%c\n", signed_char);
 // printf("%d\n", unsigned_char);

 return 0;
}
