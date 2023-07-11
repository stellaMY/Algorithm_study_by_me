#include <stdio.h>

int al[27];
int num;
int answer;

int main(){
    char str[1000001];
    scanf("%s", str);
    for(int i =0; i<1000001; i++){
        if(str[i]=='\0')break;
        if(str[i]<='Z')al[str[i]-'A']+=1;
        else al[str[i]-'a']+=1;
    }
    for(int i =0; i<27; i++){
        if(al[i]>answer){
            answer = al[i];
            num = i;
        }
        else if(al[i]==answer){
            num = 70;
        }
    }
    if(num==70)printf("?");
    else printf("%c", num+'A');
}