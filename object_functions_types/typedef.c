#include <stdio.h>

// A function that accepts int as argument and returns void
void fn_2(int i)
{

 printf("%d\n", i);
 return;
}

// fn: A function accepting int and void (*)(int) as argument, and returns a pointer to a function - the return function (fn_2) accepts int as argument and returns void
void (*fn_ret_fn_pointer_1(int a, void (*b)(int)))(int)
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
 // fn: A function accepting int and void (*)(int) as argument, and returns a pointer to a function that accepts int as argument and returns void

 fv *fn_ret_fn_pointer(int, fv *);
 fv *fn_ret_fn_pointer(int, void (*)(int));
 void (*fn_ret_fn_pointer(int, void (*)(int)))(int);

 pfv fn_ret_fn_pointer(int, pfv);
 pfv fn_ret_fn_pointer(int, void (*)(int));
 void (*fn_ret_fn_pointer(int, void (*)(int)))(int);

 ///

 // directly dereferencing the return value from the `fn` function and calling it
 (*fn_ret_fn_pointer_1(6, &fn_2))(22);

 // same as directly dereferencing as shown above
 void (*ptr)(int) = fn_ret_fn_pointer_1(6, &fn_2);
 (*ptr)(22);
 //

 return 0;
}