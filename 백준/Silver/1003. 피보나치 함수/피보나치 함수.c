#include <stdio.h>

int dpone[41];
int dpzero[41];

int main()
{
    int t;
    scanf("%d", &t);
    dpzero[0]=1;
    dpone[1]=1;
    dpone[2]=1;
    dpzero[2]=1;
    dpone[3]=2;
    dpzero[3]=1;
    for(int i =4; i<41; i++){
        dpone[i]=dpone[i-1]+dpone[i-2];
        dpzero[i]=dpzero[i-1]+dpzero[i-2];
    }
    for(int i =0; i<t; i++){
        int num;
        scanf("%d", &num);
        printf("%d %d\n", dpzero[num], dpone[num]);
    }

    return 0;
}