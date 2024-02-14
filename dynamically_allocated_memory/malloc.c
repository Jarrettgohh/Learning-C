#include <stdio.h>
#include <stdlib.h>

//
// ** the malloc function is used to allocate space for an object of a specified size whose initial value is indeterminate
//

typedef struct
{
 int i;
 double d;
} widget;

widget *widget_struct_test()
{

 widget foo_struct = {22, 1.22};
 widget *ptr = &foo_struct;

 return ptr;
}

// using dynamic memory allocation with malloc - that returns a pointer
widget *widget_struct_malloc()
{

 widget *ptr = malloc(sizeof(widget));

 if (ptr == NULL)
 {
  // Handle allocation error
  return 1;
 }

 return ptr;
}

int main()
{

 widget *widget_struct_ptr = widget_struct_test();

 printf("%d\n", widget_struct_ptr->i);
 printf("%f\n", widget_struct_ptr->d);

 widget *widget_struct_ptr_malloc = widget_struct_malloc();

 widget_struct_ptr_malloc->i = 22;
 widget_struct_ptr_malloc->d = 1.22;

 printf("%d\n", widget_struct_ptr_malloc->i);
 printf("%f\n", widget_struct_ptr_malloc->d);

 return 0;
}