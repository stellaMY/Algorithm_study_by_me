#include <stdio.h>

int main(){
    long long a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    long long num = a*a + b*b + c*c + d*d + e*e;
    num %= 10;
    printf("%lld", num);
}