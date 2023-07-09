#include <stdio.h>

char al[101];

int main(){
    scanf("%s", &al);
    int answer=0;
    int now=0;
    while(1){
        if(al[now]=='\0')break;
        now++;
        answer++;
    }
    printf("%d", answer);
}