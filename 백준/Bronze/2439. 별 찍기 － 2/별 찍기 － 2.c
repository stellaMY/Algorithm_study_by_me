#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    for(int i =num-1; i>=0; i--){
        for(int j =0; j<i; j++)printf(" ");
        for(int j = i; j<num; j++)printf("*");
        printf("\n");
    }
}