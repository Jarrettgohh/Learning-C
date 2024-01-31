#include <stdio.h>

// ********************************
// How to read pointer declaration
// ********************************

void fn(void)
{

 printf("%s\n", "fn called");
 return;
}

char *b(void)
{

 printf("%s\n", "b called");

 char a = 'A';

 char *ptr = &a;
 return ptr;
}

// returns a function pointer to a function that returns void
void (*c(void))(void)
{
 printf("%s\n", "c called");

 void (*ptr)(void) = &fn;
 return ptr;
}

// returns a function pointer to a function that returns char *
char *(*d(void))(void)
{

 printf("%s\n", "d called");

 char *(*ptr)(void) = &b;
 return ptr;
}

//  returns a function pointer to a function that returns a function pointer to a function that returns char *
char *(*(*e(void))(void))(void)
{

 printf("%s\n", "e called");

 char *(*(*ptr)(void))(void) = &d;

 ///

 // error:warning: initialization of ‘char * (**)(void)’ from incompatible pointer type ‘char * (* (*)(void))(void)’ [-Wincompatible-pointer-types]
 // reason: char * (**)(void) is a pointer to a function pointer that returns char *
 // -> due to missing the extra `(void)` after the `ptr` variable name

 // char *(*(*ptr))(void) = &d; <--
 ///

 return ptr;
}

int main()
{
 char *a; // `a` stores pointer to char

 char *b(void); // b is a function that returns a char *

 void (*c(void))(void); // c is a function that returns a function pointer (different from just simply storing) to void(void) (a function thar returns void)

 char *(*d(void))(void); // d is a function that returns a function pointer (different from just simply storing) to void *(void) (a function that returns char *)

 // e is a function that returns a function pointer to a function that returns a function pointer to a function that returns char *
 char *(*(*e(void))(void))(void);

 // f stores function pointer to void *(void) (a function that returns void *); difference between `d` and `f` is that f is a function that accepts 2 ints and the argument
 void *(*f(int, int))(void);

 ///
 void (*ptr_c)(void) = c();
 (*ptr_c)();
 ///

 ///
 char *(*ptr_d)(void) = d();
 (*ptr_d)();
 ///

 ///
 char *(*(*ptr_e)(void))(void) = e();
 (*ptr_e)();
 ///

 return 0;
}
