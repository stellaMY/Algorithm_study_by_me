#include <stdio.h>

int num;

int main(){
    scanf("%d", &num);
    for(int i =0; i<num; i++){
        int cnt;
        char str[1001];
        scanf("%d %s", &cnt, str);
        for(int j =0; j<1001; j++){
            if(str[j]=='\0')break;
            for(int k =0; k<cnt; k++){
                printf("%c", str[j]);
            }
        }
        printf("\n");
    }
}