#include <stdio.h>

long long lan[1000001];
long long first, last;
long long answer;

int main()
{
    long long num, cnt;
    scanf("%lld %lld", &num, &cnt);
    for(int i =0; i<num; i++){
        long long now;
        scanf("%lld", &now);
        lan[i]=now;
        if(now>last)last = now;
    }
    while(first<=last){
        long long mid = (first+last)/2;
        if(mid==0)mid=1;
        int tmp =0;
        int flag=0;
        for(int i =0; i<num; i++){
            tmp += lan[i]/mid;
            if(tmp>=cnt){
                flag=1;
                answer = mid;
                first = mid+1;
            }
        }
        if(flag==0)last=mid-1;
    }
    printf("%lld", answer);
}