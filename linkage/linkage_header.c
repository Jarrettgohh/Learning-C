#include <stdio.h>
#include "linkage_header.h"

// internal linkage due to `static` keyword, and is private to this file
static void test_internal_func()
{
 puts("only can be used within this file!");
}

// will implicitly be external linkage without `extern`, and does not actually need to prefix with `extern` keyword
extern void test_external_func(int v)
{
 printf("here %d\n", v);
 test_internal_func();
}

static int var1 = 4;
int var2 = 2;
