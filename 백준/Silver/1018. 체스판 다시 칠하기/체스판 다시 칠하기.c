#include <stdio.h>

char arr[51][51];
int chess[51][51];
int answer=2134567890;
int black[8][8]={
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1}
};
int white[8][8]={
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i =0; i<n; i++){
        scanf("%s", arr[i]);
        for(int j =0; j<m; j++){
            if(arr[i][j]=='B')chess[i][j]=1;
            else chess[i][j]=0;
        }
    }
    for(int i =0; i <=n-8; i++){
        for(int j =0; j<=m-8; j++){
            int tmpb=0;
            int tmpw=0;
            for(int k =i; k<i+8; k++){
                for(int l = j; l<j+8; l++){
                    if(chess[k][l]!=black[k-i][l-j])tmpb++;
                    if(chess[k][l]!=white[k-i][l-j])tmpw++;
                }
            }
            if(tmpb<answer)answer=tmpb;
            if(tmpw<answer)answer=tmpw;
        }
    }
    printf("%d", answer);
}