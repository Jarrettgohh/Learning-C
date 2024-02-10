#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void example()
{

 int *ptr, *too_far;
 long ptr_int, ptr_int_add, ptr_int_too_far;

 int arr[] = {1, 2, 3, 4};

 ptr = arr; // &arr[0]
 ptr_int = (intptr_t)ptr;
 ptr_int_add = (intptr_t)(ptr + 4); // adding value 4 (length of `arr` array) to the start memory address

 printf("Address of pointer = %ld\n", ptr_int);
 printf("Address of pointer + length of array(4) (Too-far memory address) = %ld\n", ptr_int_add);
 printf("Difference: %ld\n", ptr_int_add - ptr_int);

 printf("%s", "\n\n");

 too_far = *(&arr + 1);
 ptr_int_too_far = (intptr_t)too_far;

 printf("Too-far memory address calculated from adding 1 to the memory address of the array: %ld\n", ptr_int_too_far);

 bool same_memory_address = ptr_int_add == ptr_int_too_far;
 printf("\nValues the same: %d\n", same_memory_address);
}

void calculate_len_of_array()
{

 int arr[] = {1, 2, 3, 4};

 int arr_len_1 = (*(&arr + 1) - arr); // *(&arr + 1) - &arr[0]
 printf("%i\n", arr_len_1);
}

int main()
{

 // example();
 calculate_len_of_array();

 return 0;
}