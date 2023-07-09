#include <stdio.h>

char al[101];

int main(){
    scanf("%s", al);
    for(int i =0; i<sizeof(al); i++){
        if(al[i]=='\0')break;
        if(al[i]>='A'&&al[i]<='Z')al[i]=al[i]+32;
        else al[i]=al[i]-32;
    }
    printf("%s", al);
}