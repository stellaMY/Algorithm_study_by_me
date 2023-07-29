#include <stdio.h>

#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif

int arr[501][501];
int small = 2134567890;
int large;
int tanswer=213456790; 
int hanswer;

int main()
{
    int h, w, have;
    scanf("%d %d %d", &h, &w, &have);
    for(int i =0; i<h; i++){
        for(int j =0; j<w; j++){
            int num;
            scanf("%d", &num);
            arr[i][j] = num;
            if(num>large)large = num;
            if(num<small)small = num;
        }
    }
    int left = small;
    int right = large;
    for(int i =left; i<=min(256, large); i++){
        int mid = i;
        int now = have;
        int flag =0;
        int times =0;
        for(int i =0; i<h; i++){
            for(int j =0; j<w; j++){
                if(arr[i][j]<mid){
                    now -= mid-arr[i][j];
                    times += (mid-arr[i][j]);
                } 
                else if(arr[i][j]>mid){
                    now += arr[i][j]-mid;
                    times += 2*(arr[i][j]-mid);
                }
            }
        }
        if(now>=0){
            if(tanswer>times){
                tanswer = times;
                hanswer = mid;
            }
            else if(tanswer==times){
                hanswer = max(hanswer, i);
            }
        }
    }
    printf("%d %d", tanswer, hanswer);
    return 0;
}
