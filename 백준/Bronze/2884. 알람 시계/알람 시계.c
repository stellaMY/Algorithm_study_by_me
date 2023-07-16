#include<stdio.h>

int main(){
    int hour, min;
    scanf("%d %d", &hour, &min);
    if(min<45){
        hour--;
        if(hour<0){
            printf("%d %d", 23, min+15);
        }
        else printf("%d %d", hour, min+15);
    }
    else printf("%d %d", hour, min-45);
}