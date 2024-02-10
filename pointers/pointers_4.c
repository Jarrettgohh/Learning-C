#include <stdio.h>

// int **arr - refers to array of integer pointers

// the size value needs to be passed in as arg too - the array is decayed to a pointer upon being passed in as arg, thus calculating the length of the array within the function would fail
void arg_array_of_pointers(int **arr, size_t arr_size)
{

 for (unsigned i = 0; i < arr_size; ++i)
 {

  int *arr_value = arr[i];

  printf("%i\n", *arr_value);
 }
}

int main()
{

 int a = 4;
 int b = 5;
 int c = 6;
 int d = 7;

 int *a_ptr = &a;
 int *b_ptr = &b;
 int *c_ptr = &c;
 int *d_ptr = &d;

 int *arr[] = {a_ptr, b_ptr, c_ptr, d_ptr};
 int size = sizeof(arr) / sizeof(arr[0]);

 arg_array_of_pointers(arr, size);

 return 0;
}