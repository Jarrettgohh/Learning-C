#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOCATED_ARR_SIZE 10

// there are 4 storage durations; namely automatic, static, allocated and thread
// automatic: for those declared within a block or as a function parameter - lifetime only within execution of the block
// static: for those declared within file scope, or in block scope with explicit class specifier keyword `static` - lifetime is the entire execution of the program
// allocated: for those created with dynamically allcoted memory
// thread: concurrent programming

int static_a = 1; // static due to declaration in file scope

int main()
{

 static int static_b = 2;

 // allocated storage duration
 char *allocated_a = (char *)malloc(ALLOCATED_ARR_SIZE);

 char src[] = "012345678";

 if (sizeof src > ALLOCATED_ARR_SIZE)
 {
  fprintf(stderr, "\nInsufficient buffer space allocated -> error from Line %d \n\n", __LINE__);
  abort();
 }

 strcpy(allocated_a, src);

 {
  int automatic_a = 3;
  printf("automatic_a value: %d, I'm still here! \n", automatic_a);
 }

 // `automatic_a` will be undefined here

 printf("static_a value: %d, I'm still here! \n", static_a);
 printf("static_b value: %d, I'm still here! \n", static_b);
 printf("allocated_a value: %s, I'm still here! \n", allocated_a);

 free(allocated_a);

 return 0;
}