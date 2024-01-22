#include <stdio.h>
#include <stdlib.h>

void main(void)
{
 int num = 69;
 int *pNum = &num; // Creating a pointer for the 'num' variable declared on the line above; requires prefix of '*'; 'p' is just naming conventions i believe

 // Printing memory address
 printf("%p\n", &num); // '%p' refers to the pointer and '&' is needed too
 printf("%p\n", pNum); // Same as line above
}
