#include <stdio.h>

int *fn(int i)
{

 int *ptr = &i;

 return ptr;
}

int fn2(int i)
{

 return i;
}

int *fn3(int i)
{
 int *ptr = &i;

 return ptr;
}

int main()
{

 // A function accepting an int as argument, returning an int pointer
 int *fn(int);

 // A pointer to a function that returns an int and accepts an int as argument
 int (*fn2_ptr)(int);

 // A pointer to a function that returns an int pointer - the function accepts an int as argument
 int *(*fn3_ptr)(int);

 ///
 int *ptr = fn(6);
 printf("%p\n", ptr);
 ///

 ///
 fn2_ptr = &fn2;
 printf("%p\n", fn2_ptr);
 ///

 ///
 // fn3_ptr = fn2; // gets error
 fn3_ptr = fn;  // no error
 fn3_ptr = fn3; // no error

 printf("%p\n", fn3_ptr);
 ///

 return 0;
}