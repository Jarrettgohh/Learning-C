#include <stdio.h>
#include <string.h>

// ** NOTES **

// == OBJECT AND FUNCTION TYPES ==
// every type in C is either an object or function type
// eg. of object type is variable (int, float, etc...)
// eg. of function type is function - therefore functions are not objects, but do have types
// ** the data type int is used by default

// == SIGNED AND UNSIGNED ==
// signed data type can store positive and negative values - signed char range of value is -128 to 127
// unsigned data type can only store positive values - unsigned char range of value is 0 to 255
// --> since 1 byte of char can store 256 different values

void swap(int a, int b)
{ // function definition
}

int main(void)
{

 char *single_char = "jarrett";
 char single_char_2[10] = "jarrett";
 signed char signed_char = 'a';     // printf %d returns ASCII value
 unsigned char unsigned_char = '`'; // printf %d returns ASCII value
 signed int signed_int = -100;
 unsigned int unsigned_int = 255;

 // for (int i = 0; i < 255; ++i)
 // {
 // strncat(y, "j", 1);
 // };

 // char a[10] = "2560";
 // int b = 17;

 // printf("%lu", sizeof(single_char));
 // printf("%s\n", single_char);
 // printf("%c\n", signed_char);
 // printf("%d\n", unsigned_char);
 // printf("%d\n", signed_int);
 // printf("%u\n", unsigned_int);

 return 0;
}
