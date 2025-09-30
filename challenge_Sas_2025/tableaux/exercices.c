#include <stdio.h>

int main ()
{
    int T1[12] = {1,2,3,4,5,13,7,8,9,10,11,12};
    int T2[9] = {5,8,2,7,9,13,2,73,5};

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