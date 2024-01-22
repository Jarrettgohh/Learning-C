#include <stdio.h>
#include <stdlib.h>

void main(void)
{

 char name[20]; // Allow max 20 chars
 char startup[20];
 char mainLang[40];

 printf("\n----Basic mad libs game----\n");

 printf("Enter your name: \n");
 scanf("%s", name); //'&' is only required for single char

 printf("Enter the name of your startup: \n");
 scanf("%s", startup);

 printf("Enter the main programming language used in your startup: \n");
 scanf("%s", mainLang);

 printf("\nMy name is %s\n", name); //%s is the placeholder for string; '&' is only required for single char
 printf("I am the CEO of %s\n", startup);
 printf("The main programming language used is %s\n", mainLang);
}