#include <stdio.h>
#include <math.h>

#define cbrt(X) _Generic((X), \
    long double: cbrtl(X),    \
    float: cbrtf(X),          \
    default: cbrt(X)) // double

int main()
{

    double operand1 = 8.0;
    float operand2 = 27.0F;
    long double operand3 = 64.0L;

    // calls the macro function definition instead of the function defined in math.h
    // cast all return values as long double for highest precision

    long double val = (long double)cbrt(operand1);  // double
    long double val2 = (long double)cbrt(operand2); // float
    long double val3 = (long double)cbrt(operand3); // long double

    printf("%LF\n", val);
    printf("%LF\n", val2);
    printf("%LF\n", val3);

    return 0;
}