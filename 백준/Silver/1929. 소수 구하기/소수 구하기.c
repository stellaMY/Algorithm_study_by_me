#include <stdio.h>
#include <math.h>

int n, m;

int main()
{
    scanf("%d %d", &n, &m);
    for(int i =n; i<=m; i++){
        int flag =0;
        if(i==1)flag=1;
        for(int j =2; j<=sqrt(i); j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0)printf("%d\n", i);
    }
    return 0;
}
