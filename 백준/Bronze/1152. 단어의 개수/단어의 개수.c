#include <stdio.h>

int main(){
    int answer=0;
    char str[1000001];
    while(scanf("%s", str)!=EOF){
      answer++;
    }
    printf("%d", answer);
}