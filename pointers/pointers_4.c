#include <stdio.h>

// int **arr - refers to array of integer pointers
int arg_array_of_pointers(int **arr)
{
 //
}

int main()
{

 int a = 4;
 int b = 5;

 int *a_ptr = &a;
 int *b_ptr = &b;

 int *arr[2] = {a_ptr, b_ptr};

 arg_array_of_pointers(arr);

 return 0;
}