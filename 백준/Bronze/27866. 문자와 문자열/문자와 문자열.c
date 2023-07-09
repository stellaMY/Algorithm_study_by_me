#include <stdio.h>

int main(){
    char a[1001];
    int b;
    scanf("%s", a);
    scanf("%d", &b);
    printf("%c", a[b-1]);
}