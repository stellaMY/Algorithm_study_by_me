#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i =0; i<n; i++){
        char al[1001];
        scanf("%s", al);
        int flag=0;
        for(int i =0; i<sizeof(al); i++){
            if(al[i]=='\0'){
                flag=i;
                break;}
        }
        printf("%c%c\n", al[0], al[flag-1]);
    }
}