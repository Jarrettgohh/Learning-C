#include <stdio.h>

// same as void test(int arr[6])
void test(int *arr)
{
 // all print statements are equivalent - prints second element of
 printf("%i\n", *(arr + 1));
 printf("%i\n", arr[1]);
}

void test_2(int (*ptr)[6])
{
 printf("%i\n", *ptr[2]);
}

int main()
{

 // int *ptr = &arr[0]; // refers to arr itself

 // test(ptr); // same as test(arr);

 int arr[6] = {1, 2, 3, 4, 5};
 int(*ptr)[6] = &arr;

 test_2(ptr);

 return 0;
}