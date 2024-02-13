#include <stdio.h>
#include <limits.h>

//
// Practice exercise from the Effective C book chapter 5: Control Flow
//

int absolute_value(int a)
{

 if (a == INT_MIN)
 {
  printf("Range of signed int value exceeded! The max signed int value would be returned instead.\n");
  return -(a + 1);
 }

 if (a < 0)
 {
  return -a;
 }

 return a;
}

int main()
{

 int val;
 int int_min = INT_MIN;

 val = absolute_value(int_min); // error
 printf("Value of signed INT_MIN: %d\n", INT_MIN);
 printf("Value returned from absolute_value() function: %d\n", val);

 return 0;
}