#include<stdio.h>
int main(){
  char cara;
  printf("entre un caractere:\n");
  scanf("%c",&cara);
  switch(cara){
    case 'a': case 'e': case 'i': case 'o': case 'u':
    printf("caractere est une Voyelle ");
    break;
    default:
    printf("Ne pas Voyelle");
  }
  return 0;
}