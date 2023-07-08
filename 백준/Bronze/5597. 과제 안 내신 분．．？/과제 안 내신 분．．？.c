#include <stdio.h>

int arr[31];

int main(){
    for(int i =0; i<28; i++){
        int num;
        scanf("%d", &num);
        arr[num]=1;
    }
    for(int i =0; i<30; i++){
        if(arr[i+1]==0)printf("%d ", i+1);
    }
}