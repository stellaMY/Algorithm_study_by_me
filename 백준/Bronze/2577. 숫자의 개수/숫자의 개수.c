#include <stdio.h>

int num[11];

int main(){
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    long long now = a*b*c;
    while(now>10){
        long long cnt = now % 10;
        num[cnt]++;
        now = now / 10;
        if(now < 10) num[now]++;
    }
    for(int i =0; i<10; i++){
        printf("%d\n", num[i]);
    }
}