#include <stdio.h>
#include <stdlib.h>

// ** NOTES **
// the asterisk (*) symbol is used to declare and manipulate (dereference) pointers - a pointer is a variable that holds memory addresses of different variables of similar data types - * can be used to dereference a pointer to return the original value
// the ampersand (&) symbol refers to address of a variable in memory

void main(void)
{
 int num = 69;
 int *pNum = &num; // Creating a pointer for the 'num' variable declared on the line above; requires prefix of '*'; 'p' is just naming conventions i believe

 // Printing memory address
 printf("%p\n", &num);  // '%p' refers to the pointer
 printf("%p\n", pNum);  // Same as line above
 printf("%d\n", *pNum); // displays original value
 printf("%d\n", *&num); // displays original value - * dereferences the pointer
}
