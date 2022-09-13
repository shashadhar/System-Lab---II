
#include <stdio.h>
int main() {
int arg1=51, arg2=15,arg3;

printf("arg1 = %d\n", arg1);
printf("arg2 = %d\n",arg2);

 /* Perform swap of two variable */
 __asm__ ( "movl %%eax, %%ecx;" "movl %%ebx, %%eax;" "movl %%ecx, %%ebx;" : "=c" (arg3),"=a"(arg1),"=b" (arg2) : "a" (arg1) , "b" (arg2) );


printf("\narg1 = %d\n", arg1);
printf("arg2 = %d\n",arg2);


 return 0;
}
