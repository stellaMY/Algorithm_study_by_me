#include <stdio.h>

int answer;
int cnt;

int main(){
    for(int i =0; i<9; i++){
        int num;
        scanf("%d", &num);
        if(answer<num){
            answer = num;
            cnt =i+1;}
    }
    printf("%d\n%d", answer, cnt);
}