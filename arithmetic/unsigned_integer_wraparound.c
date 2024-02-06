#include <stdio.h>
#include <limits.h>

int main()
{

 // wraparound occurs for an unsigned integer type when when there is an arithmetic operation that results in values that are too small (less than 0) or large (greater than 2^(N-1))

 unsigned int ui = UINT_MAX;
 ui++; // increase above max allowed range - wraparounds to 0
 printf("%u\n", ui);

 ui--; // decrease by 1, falls outside the range - wraparounds to UINT_MAX
 printf("%u\n", ui);

 return 0;
}