#include <stdio.h>

int check[100001];
char str[200004];
int flag;

int main()
{
    int n;
    scanf("%d", &n);
    int now=0;
    int cnt =0;
    for(int j =0; j<n; j++){
        int num;
        scanf("%d", &num);
        if(num<=now){
            for(int i =now; i>num; i--){
                if(check[i]==2)continue;
                else if(check[i]==1){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
            if(flag==0){
                check[num]=2;
                str[cnt]='-';
                cnt++;
            }
        }
        else{
            for(int i =now+1; i<num;i++){
                str[cnt]='+';
                cnt++;
                check[i]=1;
            }
            str[cnt]='+';
            cnt++;
            check[num]=2;
            str[cnt]='-';
            cnt++;
            now = num;
        }
    }
    if(flag==0){
        for(int i =0; i<200004; i++){
            if(str[i]=='\0')break;
            printf("%c\n", str[i]);
        }
    }
    else printf("NO");
    return 0;
}
