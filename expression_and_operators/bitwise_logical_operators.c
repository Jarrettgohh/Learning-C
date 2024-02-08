#include <stdio.h>
#include <stdarg.h>

void bitwise_and();
void bitwise_xor();
void bitwise_or();

// void bitwise_and(int vals[2][2]) - same
void bitwise_and(int (*vals)[2])
{
 for (unsigned row = 0; row < 1; ++row)
 {

  int val1 = vals[row][0];
  int val2 = vals[row][1];

  int and = val1 & val2; // 1000 ^ 1100 = 1000; output: 8
  printf("%i & %i = %i\n", val1, val2, and);
 }
}

// void bitwise_xor(int vals[2][2]) - same
void bitwise_xor(int (*vals)[2])
{
 for (unsigned row = 0; row < 1; ++row)
 {
  int val1 = vals[row][0];
  int val2 = vals[row][1];

  int and = val1 ^ val2; // 1000 ^ 1100 = 0100; output: 4
  printf("%i ^ %i = %i\n", val1, val2, and);
 }
}

// void bitwise_or(int vals[2][2]) - same
void bitwise_or(int (*vals)[2])
{
 for (unsigned row = 0; row < 1; ++row)
 {
  int val1 = vals[row][0];
  int val2 = vals[row][1];

  int and = val1 | val2; // 1000 | 1100 = 1100; output: 12
  printf("%i | %i = %i\n", val1, val2, and);
 }
}

int main()
{
 // bitwise AND (&)
 // bitwise XOR - exclusive OR (^)
 // bitwise OR - inclusive OR (|)

 int a = 8;  // 1000
 int b = 12; // 1100

 int vals[2][2] = {{a, b}}; // {{8, 12}}
 int(*ptr)[] = &vals[0];
 int(*ptr_matrix)[2][2] = &vals;

 bitwise_and(ptr);         // same as bitwise_and(vals);
 bitwise_xor(*ptr_matrix); // same as bitwise_xor(vals);
 bitwise_or(vals);

 return 0;
}
