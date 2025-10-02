#include <stdio.h>

int main ()
{
   int T1[7]={1,6,7,8,9,8,3};
  int T2[4]={9,2,3,2};
    int num;
    int found = 0;

    printf("enter the number: ");
    scanf("%d",&num);

    for (int i = 0; i <= (sizeof(T1) / sizeof(T1[0])); i++)
    {
        for (int j = 0 ; j <= (sizeof(T2) / sizeof(T2[0])); j++)
        {
            if ((T1[i] + T2[j]) == num)
            {
                printf("T1[%d] + T2[%d] = %d \n",i ,j,num);
                found = 1;
            }
        }
    }
    if (!found)
    {
        printf("the number %d is not found\n",num);
    }
    return 0;
}