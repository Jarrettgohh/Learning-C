#include <stdio.h>
#include <stdlib.h>

void main(void)
{

 // Need define variables on the top first before usage
 char name[] = "Jarrett";
 int oranges = 10;
 float price = 0.80;
 int arrayTest[10] = {1, 2, 3, 4};

 printf("%s bought %d oranges, each orange costs $%.2f\n", name, oranges, price); // %.2f is 2 d.p float
 printf("%d", arrayTest[1]);
}