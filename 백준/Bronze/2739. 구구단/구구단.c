#include <stdio.h>

int n;

int main(){
    scanf("%d", &n);
    for(int i =1; i<=9; i++){
        printf("%d * %d = ", n, i);
        printf("%d\n", n*i);
    }
}