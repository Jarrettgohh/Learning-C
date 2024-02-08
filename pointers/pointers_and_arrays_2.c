#include <stdio.h>

void char_matrix(char (*matrix)[4])
{

 // char *arr = *arr_ptr; // *&&arr[0]
 // printf("%c\n", **arr_ptr);

 for (unsigned i = 0; i < 4; ++i)
 {

  char val[4] = matrix[i];

  // printf("%c\n", *matrix[i]); //
 }
}

// arg takes in pointer to first arg of an array - referring to the array itself
void char_arr(char *arr)
{

 printf("%c\n", *arr); // *arr = *&arr[0] simply prints first element of array

 for (unsigned i = 0; i < 4; ++i)
 {
  printf("%c\n", arr[i]);
 }
}

int main()
{
 char arr[6] = {'1', '2', '3', '4'};
 char matrix[4][4] = {{'1', '2', '3', '4'}, {'2', '2', '3', '4'}};

 // char_arr(arr);

 char(*ptr)[4] = &matrix[0];
 char_matrix(ptr);

 return 0;
}