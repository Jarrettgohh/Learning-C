#include <stdio.h>
#include <stdint.h>

// function that gives a basic implementation of the C standard library strlen() function
size_t strlen_test(const char *str)
{

 const char *s = str;

 // initializes `s` to the string passed in as argument - value is not updated throughout the running of the loop
 // *s conditions states that the for loop would stop running when the value of *s is NULL - null terminator encountered
 // ++s equivalent to s = s + 1 does pointer arithmetic and assigns s to the memory address of the element moving from element 0 all the way to a null terminator
 for (s = str; *s; ++s)
 {
 }

 printf("Memory address of the last element (referenced by s): %p\n", s);
 printf("Memory address of the first element (referenced by str; &str[0]): %p\n", str);
 printf("Integer representation of the last element (referenced by s): %ld\n", (intptr_t)s);
 printf("Integer representation of the last element (referenced by str; &str[0]): %ld\n", (intptr_t)str);

 // performing pointer arithmetic, to minus the memory address of the first element of array from the memory address of the last element of array right before the null-terminator
 return s - str;
}

int main()
{

 size_t len = strlen_test("jarrett");
 printf("%lu\n", len);

 return 0;
}