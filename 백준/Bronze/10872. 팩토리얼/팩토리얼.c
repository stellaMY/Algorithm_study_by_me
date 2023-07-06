#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int answer = 1;
    for(int i =1; i<=n; i++){
        answer = answer*i;
    }
    printf("%d", answer);
}