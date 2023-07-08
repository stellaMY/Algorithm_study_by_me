#include <stdio.h>

int arr[101][101];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i =0; i<2; i++){
        for(int j =0; j<n; j++){
            for(int k =0; k<m; k++){
                int num;
                scanf("%d", &num);
                arr[j][k] += num;
            }
        }
    }
    for(int j =0; j<n; j++){
            for(int k =0; k<m; k++){
                printf("%d ", arr[j][k]);
            }
        printf("\n");
        }
}