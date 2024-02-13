#include <stdio.h>

void goto_statement(int a)
{
 switch (a)
 {

 case 1:
  goto one;

 case 2:
  goto two;

 case 3:
  goto three;

 default:
  goto fail;
 }

one:
 printf("one\n");
 return;

two:
 printf("two\n");
 return;

three:
 printf("three\n");
 return;

fail:
 printf("fail\n");
 return;
}

int main()
{

 goto_statement(1);
 // goto_statement(2);
 // goto_statement(3);

 return 0;
}