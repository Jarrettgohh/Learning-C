#include <stdio.h>
#include <stdlib.h>

typedef struct
{
 size_t num;
 int data[];
} widget;

void *func(size_t array_size)
{
 widget *p = (widget *)malloc(sizeof(widget) + sizeof(int) * array_size);

 if (p == NULL)
 {
  return NULL;
 }

 p->num = array_size;

 for (size_t i = 0; i < p->num; ++i)
 {
  p->data[i] = 22;
 }

 printf("%d\n", (*p).data[0]);
 printf("%d\n", (*p).data[1]);
 printf("%d\n", (*p).data[2]);
 printf("%d\n", (*p).data[3]);
}

int main()
{

 size_t array_size = 4;

 func(array_size);

 return 0;
}