#include <stdio.h>

//
// ** the name of an array is actually a pointer to the first element of the array
//
// ==> arr + i == &arr[i]
// ==> *(arr + i) === arr[i] - add indirection (*) opearator to both sides

void int_arr()
{

 int arr[10] = {1, 2, 3, 4};

 printf("%p\n", &arr[3]);

 int *p1 = &arr[1];
 int *p2 = arr + 1; // basically refers to the memory address of the second element in the array (same as line above: &arr[1])

 printf("%p\n", p1);
 printf("%p\n", p2);

 int *p3 = arr + 2;
 *p3 = 5;

 // printf("%lu\n", *(&arr + 1) - arr); // length of array (?)

 for (unsigned i = 0; i < 4; ++i)
 {
  printf("%d\n", *(arr + i)); // value of the element in the array at each index
  printf("%p\n", arr + i);    // memory address of the element in the array at each index
 }
}

void char_arr()
{
 char arr[10] = {'1', '2', '3', '4'};

 char *p1 = arr;

 printf("%p\n", p1);

 //
 // update element in array from the pointer
 //

 char *ptr1 = arr + 1;
 char *ptr2 = &arr[2];
 *ptr1 = 'j';
 *ptr2 = 'g';

 //
 //
 //

 for (unsigned i = 0; i < 4; ++i)
 {
  printf("%c\n", *(arr + i));
  printf("%p\n", arr + i);
 }
}

void int_matrix()
{

 int matrix[3][3];

 int *p1 = &matrix[0][0];
 int *p2 = &matrix[2][0];

 printf("%p\n", p1);
 printf("%p\n", p2);

 unsigned long int diff = p2 - p1;
 printf("%lu\n", diff);
}

int main(void)
{
 // int_arr();
 char_arr();
 // int_matrix();

 // int arr[3][5];
 // int x = arr[0][0];

 // printf("%d\n", x);

 return 0;
}