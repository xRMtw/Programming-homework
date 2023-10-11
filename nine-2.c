#include<stdio.h>
int main(){
for(int k=0;k<=2;k+=1){
    printf("\n");
    for(int j=1;j<=9;j+=1)        
        for(int i=1+k;i<=9;i+=3){
            printf("%dx%d=%2d\t",i,j,i*j);
            if(i>=7){
                printf("\n");
            }
        }
    } 
}