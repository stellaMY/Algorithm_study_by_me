#include <stdio.h>

int main(){
    int one =0;
    int two=0;
    int arr[10];
    for(int i =0; i<8; i++){
        scanf("%d", &arr[i]);
        if(i!=0){
            if(arr[i-1]<arr[i])two++;
            else if(arr[i-1]>arr[i])one++;
        }
    }
    if(one>=1&&two>=1)printf("mixed");
    else if(one>=1&&two==0)printf("descending");
    else if(one==0&&two>=1) printf("ascending");
}