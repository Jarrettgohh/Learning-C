#include <stdio.h>

// same as void test(int arr[6])
void test(int *arr)
{
 // all print statements are equivalent - prints second element of the array
 printf("%i\n", *(arr + 1));
 printf("%i\n", arr[1]);
}

void test_2(int (*ptr)[6])
{

 int *v = *ptr;

 printf("%i\n", *ptr[2]); // would not work as in the expression: *ptr[2], the
 printf("%i\n", v[2]);    // prints 3rd element of array
 printf("%i\n", **ptr);   // same as *(*&ptr[0]); prints the first element of the array (* operator is right associative)
 printf("%i\n", *(*&ptr[0]));
}

int main()
{

 int arr[6] = {1, 2, 3, 4, 5};

 // int *arr_ptr = &arr[0]; // refers to arr itself
 // test(arr);
 // test(arr_ptr); // same as test(arr);

 int(*arr_ptr_2)[6] = &arr; // works to pass array to function, but seems quite pointless and irrelevant, as the array could be directly pass instead - as with test() function

 test_2(arr_ptr_2);

 return 0;
}