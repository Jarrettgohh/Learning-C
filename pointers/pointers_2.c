#include <stdio.h>
#include <string.h>

void swap_1(int *pA, int *pB)
{
 int t = *pA;

 *pA = *pB;
 *pB = t;

 printf("a = %d, b = %d", *pA, *pB);
 printf("\n");
}

void swap_2(int *pA, int *pB)
// does not work to update variables in main function - not able to update variable based on pointer to the memory address location, but rather the value stored in the memory address location as with swap_1() function
{

 int *pT = pA;

 pA = pB;
 pB = pT;

 printf("a = %d, b = %d", *pA, *pB);
 printf("\n");
}

int main(void)
{

 int a = 12;
 int b = 20;

 // swap_1(&a, &b);
 swap_2(&a, &b);

 printf("a = %d, b = %d", a, b);
 printf("\n");
}