#include <stdio.h>

int main(){
    long long n, m;
    scanf("%lld %lld", &n, &m);
    long long answer = n-m;
    if(answer <0)printf("%lld", -answer);
    else printf("%lld", answer);
}