#include <stdio.h>

int answer;
int arr[101];

int main(){
    int n;
    scanf("%d", &n);
    for(int i =0; i<n; i++){
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }
    int v;
    scanf("%d", &v);
    for(int i =0; i<n; i++){
        if(arr[i] == v)answer+=1;
    }
    printf("%d", answer);
}