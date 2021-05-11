#include <stdio.h>
#include <stdlib.h>

void main(void)
{

 // Need define variables on the top first before usage
 char name[] = "Jarrett";
 int oranges = 10;
 float price = 0.80;

 printf("%s bought %d oranges, each orange costs $%.2f", name, oranges, price); // %.2f is 2 d.p float
}