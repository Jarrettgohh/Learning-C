#include <stdio.h>

int struct_eg_1()
{

 struct s
 {
  int x;
  char y;
 } struct_1, *struct_ptr;

 struct_ptr = &struct_1;
 struct_ptr->x = 6;
 struct_ptr->y = 'g';

 printf("%d\n", struct_1.x);
 printf("%c\n", struct_1.y);
}

int struct_eg_2()
{
 typedef struct s struct_def;

 struct s
 {
  int x;
  char y;
 };

 struct_def struct_1 = {22, 'j'}; // same as struct s struct_1 = {22, 'j'}

 struct_def *struct_ptr = &struct_1; // same as struct s *struct_ptr = &struct_1;

 struct_ptr = &struct_1;
 struct_ptr->x = 6;
 struct_ptr->y = 'g';

 printf("%d\n", struct_1.x);
 printf("%c\n", struct_1.y);
}

int main()
{

 // struct_eg_1();
 struct_eg_2();

 return 0;
}