#include <stdio.h>
#include <stdlib.h>

int main()
{
   int T[7];
   for(int i=0; i<7;i++){
    printf("%d-donner moi un nombre entie:",i+1);
    scanf("%d",&T[i]);
   }
   for(int i=0; i<7;i++){
    printf("T[%d]=%d\n",i,T[i]);
   }
   
    return 0;
}
