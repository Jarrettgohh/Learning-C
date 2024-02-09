#include <stdio.h>

void int_matrix(int (*matrix)[4])
{

 int *arr = *matrix; // *&matrix[0] dereference the pointer to the first array element of the matrix - C converts the array to a pointer to the first element of the array (int)
 int v = arr[3];

 printf("%d\n", v);

 for (unsigned i = 0; i < 2; ++i)
 {
  for (unsigned x = 0; x < 4; ++x)
  {
   int val = matrix[i][x];

   printf("%d\n", val);
  }

  printf("%s\n", "\n");
 }
}

// arg takes in pointer to first arg of an array - referring to the array itself
void int_arr(int *arr)
{

 printf("%d\n", *arr);       // *arr = *&arr[0] simply prints first element of array
 printf("%d\n", *(arr + 1)); // prints second element of the array

 for (unsigned i = 0; i < 4; ++i)
 {
  printf("%c\n", arr[i]);
 }
}

int main()
{
 int arr[6] = {9, 2, 3, 4};
 int matrix[2][4] = {{1, 10, 5, 6}, {2, 2, 3, 4}};

 // int *arr_ptr = &arr[0];
 // int_arr(arr_ptr);

 int(*matrix_ptr)[4] = &matrix[0]; // creating pointer to first element in matrix - first element is basically an array of length 4
 int_matrix(matrix);

 return 0;
}