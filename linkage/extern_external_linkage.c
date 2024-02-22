#include <stdio.h>
#include "linkage_header.h"

//
// ****  needs to be linked with the implementation file `linkage_header.c` to work
// $> ...desktop/learning-c/linkage$ ../run.sh -f extern_external_linkage.c -l linkage_header.c
//

// extern keyword used to:
// 1. access a variable defined in another file
// 2. create a global common variable that can be used in all files that are linked together
// **
// -> gives external linkage
// -> only used to declare, not define
// -> the keyword essentially tells the compiler that the variable is defined in another file

int main()
{
 extern int var1;
 // printf("%d\n", var1); // gets error as `var1` is declared as static in `linkage_header.c`

 extern int var2; //  declared in `linkage_header.c`

 var2 = 8; // works when re-assigning
 // int var2 = 8; // however, gets error when re-defining

 printf("%d\n", var2);

 test_external_func(22); // declared in `linkage_header.c`

 return 0;
}