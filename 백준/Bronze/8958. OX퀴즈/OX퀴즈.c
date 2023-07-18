#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i =0; i<n; i++){
        char str[100];
        scanf("%s", str);
        int answer =0;
        int cnt=0;
        if(str[0]=='O'){
            cnt=1;
            answer=1;
        }
        for(int i =1; i<80; i++){
            if(str[i]=='\0')break;
            if(str[i]=='O'){
                cnt++;
                answer+=cnt;
            }
            else cnt=0;
        }
        printf("%d\n", answer);
    }
}