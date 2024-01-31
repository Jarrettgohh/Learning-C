#include <stdio.h>

// A function that accepts int as argument and returns void
void fn_2(int i)
{

 printf("%d\n", i);
 return;
}

// fn: A function accepting int and void (*)(int) as argument, and returns a pointer to a function - the return function (fn_2) accepts int as argument and returns void
void (*fn(int a, void (*b)(int)))(int)
{

 // ptr: pointer to a function accepting int as argument and returns void
 void (*ptr)(int) = &fn_2;
 return ptr;
}

int main()
{
 // char *: pointer to char
 // int *: pointer to int
 // fv *: pointer to typedef `fv`

 // fv: A function accepting int as argument, and returning void
 // pfv: A pointer to function accepting int as argument and returning void -> fv *
 typedef void fv(int), (*pfv)(int);

 ///
 // fv *fn(int, fv *);
 // fv *fn(int, void (*)(int));
 // void (*fn(int, void (*)(int)))(int);

 void (*fn(int, void(int)))(int);
 ///

 // directly dereferencing the return value from the `fn` function and calling it
 (*fn(6, fn_2))(22);

 // pfv fn(int, pfv);

 return 0;
}