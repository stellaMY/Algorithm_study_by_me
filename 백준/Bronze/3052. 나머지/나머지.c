#include <stdio.h>

int arr[45];

int main(){
    int answer=0;
    for(int i =0; i<10; i++){
        int n;
        scanf("%d", &n);
        int now = n %42;
        if(arr[now]==0){
            answer++;
            arr[now]=1;}
    }
    printf("%d", answer);
}