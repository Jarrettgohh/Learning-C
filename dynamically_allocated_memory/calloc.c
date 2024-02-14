#include <stdio.h>
#include <stdlib.h>

// ** calloc is used to allocate storage for an array
// void *calloc(size_t nmemb, size_t size)
//
// Where:
// nmemb: number of objects in the array
// size: size in bytes of each member
//

int main()
{

 int *calloc_arr = (int *)calloc(4, sizeof(int)); // allocate memory for int array with size 4, and cast it to the type of pointer to int (first element of array)

 if (calloc_arr == NULL)
 {
  printf("Failed to allocate memory.");
  return EXIT_FAILURE; // same as return 1;
 }

 calloc_arr[1] = 22;

 for (unsigned i = 0; i < 4; i++)
 {
  printf("%d\n", calloc_arr[i]);
 }

 return EXIT_SUCCESS; // same as return 0;
}