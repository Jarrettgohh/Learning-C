#include <stdio.h>
#include "linkage_header.h"

//
// ****  needs to be linked with the implementation file `linkage_header.c` to work
// $> ...desktop/learning-c/linkage$ ../run.sh -f static_internal_linkage.c -l linkage_header.c
//

// static keyword besides for the storage duration, gives internal linkage
// 1. allows the same variable name to be declared - unlike extern

static void test_internal_func()
{
 puts("I can have my own private function too!");
}

void call1()
{
 // ** remove the function definition for static void test_internal_func() above first before running this function - to simulate trying to access function directly from linkage.header.c

 extern void test_internal_func();

 test_internal_func(); // will get error: undefined reference to `test_internal_func', as trying to access static function (defined in linkage_header.c) with extern keyword
}

void call2()
{
 test_internal_func(); // however, can define own static (private) function too with the same name
}

int main()
{

 static int var1; // doesn't take the value from the `var1` variable defined in "linkage_header.c", since the variable in this file is declared as static - declares a new variable

 printf("%d\n", var1); // prints 0 - before definition

 var1 = 6;

 printf("%d\n", var1); // prints 6 - after definition

 // call1();
 call2();

 return 0;
}