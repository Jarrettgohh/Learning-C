#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
 char name[20];
 char adminNum[10];
 char cca[20];
 char course[40];
 double gpa;
} student1; // Same as "struct Student student1" statement

void main(void)
{

 // Init student1
 strcpy(student1.name, "Jarrett");
 strcpy(student1.adminNum, "192264W");
 strcpy(student1.cca, "Badminton");
 strcpy(student1.course, "Nanotechnology & Materials Science");
 student1.gpa = 3.82;

 printf("%s\n", student1.name);
 printf("%s\n", student1.adminNum);
 printf("%s\n", student1.cca);
 printf("%s\n", student1.course);
 printf("%.2f\n", student1.gpa);
}