#include <stdio.h>
#include <stdlib.h>

void malloc_free()
{

 unsigned *ptr = NULL;
 // printf("%d\n", *(signed *)ptr); // segmentation fault: de-referencing NULL pointer

 ptr = malloc(sizeof(unsigned));
 *ptr = 22;

 free(ptr);

 printf("%u\n", *ptr);
}

int main()
{
 malloc_free();

 return 0;
}