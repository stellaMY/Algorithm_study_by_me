#include <stdio.h>

int main(){
    int n, max;
    scanf("%d %d", &n, &max);
    for(int i =0; i<n; i++){
        int num;
        scanf("%d", &num);
        if(num<max){
            printf("%d ", num);
        }
    }
}