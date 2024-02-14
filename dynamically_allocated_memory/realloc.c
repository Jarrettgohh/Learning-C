#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// ** realloc is used to re-allocate memory storage for a previously allocated one (with either malloc, calloc, or aligned_alloc)
// void *realloc(void *ptr, size_t size)
//
// Where:
// ptr: pointer to previously allocated memory
// size: new size of memory to allocate

// ** general concept of how realloc() function works:
// 1. the malloc() function is called to allococate a new memory storage of the new size
// 2. the contents of the old storage is transferred to the new memory storage
// 3. if it succeeds, the free() functon is called to de-allocate the old memory storage
// 4. if it fails, the old object data will be retained at the same old address, and a null pointer is returned

// ** To demostrate the following in the examples:
// 1. simulate realloc() function failing
// -> eg. p = realloc(p, size);
// -> p assigned value NULL, while the old storage referenced by p is not deallocated

//  2. memory leak; free() function not working if the same variable name as argument is assigned for realloc() function
//  -> eg. p = realloc(p, size);
//  -> variable p is converted to a NULL pointer, causing a segmentation fault when accessed(?)

// 3. simulate realloc() function succeeding
// -> print sizeof data type value of new pointer and the value assigned (to assign a test value first)

//
// 4. free() function working
// -> old pointer gets segmentation fault when accessed(?)
//

void realloc_fail_memory_leak()
{
 // a memory leak can occur when realloc() fails to allocate a new storage, causing the old storage to be retained, while returning a null pointer, and the free() function is not called to free the object data from the old storage, causing a memory leak
 // this can happen when the same variable name is used to store the results of the realloc() function, resulting in a null pointer, while the memory storage at the old address being un-used and not able to be freed.

 unsigned long long size = (unsigned long long)(1 * (pow(10, 9))); // 1GB of memory
 void *p = malloc(sizeof(unsigned long long));

 if (p == NULL)
 {
  // expected to work
  printf("Failed to allocate memory with malloc().\n");
  return;
 }

 // assign a test value referenced by the pointer
 *(unsigned *)p = 22;

 // re-allocation of memory would fail; assuming that 18 GB (18 * 10^9 bytes) exceeds the maximum allowed memory space
 size += (unsigned long long)(18 * (pow(10, 9)));

 //  assigning the old pointer to another pointer - for testing purpose to check if the free() function works
 void *p2 = p;

 p = realloc(p, size);

 // re-allocate pointer to the same variable name
 if ((p = realloc(p, size)) == NULL)
 {
  printf("Failed to re-allocate memory with realloc()\n");
  free(p); // doesn't actually de-allocate the memory referenced by p, since p is reassigned to a null pointer alr - memory leak
 }

 // value referenced by the old memory address is not de-allocated
 printf("Value referenced by the old memory address: %d (not de-allocated)\n", *(unsigned *)p2);

 printf("%u\n", *(unsigned *)p); // causes a segmentation fault due to the de-referencing of a NULL pointer variable `p`
}

void realloc_fail_proper_free_memory()
{

 unsigned long long size = (unsigned long long)(1 * (pow(10, 9))); // 1GB of memory

 void *p1 = malloc(sizeof(unsigned long long));
 void *p2;

 if (p1 == NULL)
 {
  printf("Failed to allocate memory with malloc().\n");
  return;
 }

 *(unsigned *)p1 = 1000;

 size += (unsigned long long)(18 * (pow(10, 9)));

 if ((size == 0) || ((p2 = (unsigned *)realloc(p1, size)) == NULL))
 {
  printf("Failed to re-allocate memory with realloc()\n");
  printf("Value stored in memory address `p1` before free() function: %u\n\n", *(unsigned *)p1);

  printf("Freeing the memory referenced by `p1`...\n");
  free(p1); // free the memory address referenced by `p1`, as `p2` is used to reference the new memory address, `p1` is not changed to a null pointer (`p2` will be a NULL pointer instead) when the realloc() function fails
  // `p1`; that is still referencing the old memory address can be de-allocated using the free() function to properly free it
 }

 printf("Value stored in memory address `p1` after free() function: %u\n", *(unsigned *)p1);

 // causes segmentation fault as the `p2` pointer is NULL
 printf("%d\n", *(unsigned *)p2);
}

void realloc_succeed()
{

 unsigned long size = sizeof(int);

 unsigned *p1 = malloc(size);
 unsigned long *p2;

 if (p1 == NULL)
 {
  printf("Failed to allocate memory with malloc().\n");
  return;
 }

 size += 100;

 *p1 = 22;

 printf("Pointer address before realloc() function: %p\n\n", p1);

 if ((size == 0) || ((p2 = (unsigned long *)realloc(p1, size)) == NULL))
 {
  printf("Failed to re-allocate memory with realloc().\n");
  free(p1);
  return;
 }

 *p2 = 44;

 printf("Size of pointer p1: %lu\n", sizeof(*p1));
 printf("Size of pointer p2: %lu\n", sizeof(*p2));
 printf("\n");
 printf("Value referenced by pointer p1: %u\n", *p1);
 printf("Value referenced by pointer p2: %lu\n", *p2);
 printf("\n");
 printf("Pointer address of p1: %p\n", p1);
 printf("Pointer address of p2: %p\n", p2);
}

int main()
{

 // realloc_fail_memory_leak();
 // realloc_fail_proper_free_memory();
 realloc_succeed();

 return 0;
}