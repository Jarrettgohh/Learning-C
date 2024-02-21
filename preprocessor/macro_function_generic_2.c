#include <stdio.h>
#include <math.h>

//
// NOTE: to run gcc with -lm option for <math.h> sin() function to work
//

#define sin(X) _Generic((X), \
    long double: sinl,       \
    float: sinf,             \
    double: sin)(X) // double

int main()
{

 double operand1 = 1.5708;
 float operand2 = 1.5708F;
 long double operand3 = 1.5708L;

 double val = sin(operand1);       // double
 float val2 = sin(operand2);       // float
 long double val3 = sin(operand3); // long double

 printf("%lf\n", val);
 printf("%F\n", val2);
 printf("%LF\n", val3);

 return 0;
}