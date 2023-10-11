#include <stdio.h>

int main()
{
  for (int i = 1; i <= 9; i++){
    for (int j = 1; j <= 9; j++){
        printf("%dx%d=%2d ",j,i,i * j);
        if(j==9){
            printf("\n");
        }
      }
  }
}