#include <stdio.h>
#include <string.h>

void f(char *s)
{
  char buf[5];
  strcpy(buf, "s: ");
  strcat(buf, s); // wrong: buffer not checked before strcat
}

void g(char *s)
{
  char buf[5];
  strcpy(buf, "s: ");
  if (strlen(s) < 77)
    strcat(buf, s); // correct: buffer size checked before strcat
}

void test(char s[20])
{

  printf("%s\n", s);
}

int main()
{

  char bad_str[10] = "GJJJJJJJJJ";
  char *ptr = &bad_str[0]; // strings are array, so pointer to first element refers to the name of the string variable

  // f(ptr);
  printf("%c\n", *ptr);       // prints 'G' - the first letter of the string
  printf("%s\n", ptr);        // prints the entire string
  printf("%c\n", *(ptr + 1)); // prints 'J' - the second letter of the string

  return 0;
}