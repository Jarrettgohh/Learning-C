#include <stdio.h>

typedef enum
{
 Apple,  // 0
 Banana, // 1
 Orange, // 2
 Mango   // 3
} Fruit;

void basic_enum_example()
{

 Fruit fruit = Banana;
 printf("%d\n", fruit);

 printf("%d\n", Mango); // printing directly works too
}

void enum_with_switch(Fruit fruit)
{

 switch (fruit)
 {

 case Apple:
  printf("apple\n");
  break;

 case Banana:
  printf("banana\n");
  break;

 case Orange:
  printf("orange\n");
  break;

 case Mango:
  printf("mango\n");
  break;

 default:
  printf("provid a fruit\n");
  break;
 }
}

int main()
{

 // basic_enum_example();

 Fruit fruit = Mango;

 enum_with_switch(Mango);
 enum_with_switch(fruit); // same as passing `Mango` directly as argument

 return 0;
}