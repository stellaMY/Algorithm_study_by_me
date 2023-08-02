#include <stdio.h>
#include <math.h>

int n, r, c;
int answer, sized;

void check(int y, int x, int sized){
    if(y==r&&x==c){
        printf("%d", answer);
        return;
    }
    if(r<y+sized&&r>=y&&c<x+sized&&c>=x){
        check(y, x, sized/2);
        check(y+sized/2, x, sized/2);
        check(y, x+sized/2, sized/2);
        check(y+sized/2, x+sized/2, sized/2);
    }
    else answer += sized *sized;
}

int main()
{
    scanf("%d %d %d", &n, &c, &r);
    sized = pow(2, n);
    check(0,0,sized);
    return 0;
}
