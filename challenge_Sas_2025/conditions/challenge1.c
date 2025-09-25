#include<stdio.h>

int main(){
  printf("entre un nombre entie:\n");
  int n;
  scanf("%d",&n);
  if (n%2 == 0){
    printf("%d -> nombre pair ",n);
  }
  else{
    printf("%d -> nombre impair",n);
  }

    return 0;
}