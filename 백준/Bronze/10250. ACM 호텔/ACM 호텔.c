#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i =0; i<n; i++){
        int h, w, num;
        scanf("%d %d %d", &h, &w, &num);
        int rest = num % h;
        if(rest==0){
            if(num/h<10){
                printf("%d%d%d\n", h, 0, num/h);
            }
            else printf("%d%d\n", h, num/h);
        }
        else{
            if(num/h+1<10){
                printf("%d%d%d\n", rest, 0, num/h+1);
            }
            else printf("%d%d\n", rest, num/h+1);
        }
    }
}