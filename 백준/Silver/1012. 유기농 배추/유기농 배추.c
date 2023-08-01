#include <stdio.h>

int ground[51][51];
int visited[51][51];
int ydir[]={0,0,1,-1};
int xdir[] = {1,-1,0,0};
int n, m, t;

void itsok(int y, int x){
    visited[y][x]=1;
    for(int i =0; i<4; i++){
        int ny = y + ydir[i];
        int nx = x + xdir[i];
        //if(ny<0||nx<0||ny>=n||ny>=m)continue;
        if(ground[ny][nx]==1 && visited[ny][nx]==0){
            itsok(ny, nx);
        }
    }
}

int main()
{
    int k;
    scanf("%d", &k);
    for(int i =0; i<k; i++){
        int answer =0;
        scanf("%d %d %d", &m, &n, &t);
        for(int i =0; i<t; i++){
            int y, x;
            scanf("%d %d", &x, &y);
            ground[y][x]=1;
        }
        for(int j =0; j<n; j++){
            for(int k=0; k<m; k++){
                if(ground[j][k]==1 && visited[j][k]==0){
                    answer+=1;
                    itsok(j, k);
                }
            }
        }
        printf("%d\n", answer);
        for(int l =0; l<51; l++){
            for(int j =0; j<51; j++){
                ground[l][j]=0;
                visited[l][j]=0;
            }
        }
    }
    return 0;
}