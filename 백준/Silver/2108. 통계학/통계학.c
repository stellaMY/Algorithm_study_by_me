#include <stdio.h>
#include <stdlib.h>

int arr[500001];
int check[8002];
int small=5000;
int large=-5000;
double all;

int compare(const void *a, const void *b) {
    if(*(int*)a > *(int*)b) {
        return 1;
    }
    else if(*(int*)a < *(int*)b) {
        return -1;
    }
    else {
        return 0;
    }
}

int main()
{
    double n;
    scanf("%lf", &n);
    for(int i =0; i<n; i++){
        int nn;
        scanf("%d", &nn);
        arr[i]=nn;
        all+=nn;
        check[nn+4000]+=1;
        if(nn<small)small=nn;
        if(nn>large)large=nn;
    }
    int result=0;
    if(all>0)result = (int)(all/n+0.5);
    else result = (int)(all/n -0.5);
    printf("%d\n", result);
    qsort(arr, n, sizeof(int), compare);
    int result2 = (int)(n/2);
    printf("%d\n", arr[result2]);
    int first=0;
    int firstindex=0;
    int flag=0;
    for(int i =0; i<8002; i++){
        if(first<check[i]){
            first = check[i];
            firstindex = i-4000;
            flag=0;
        }
        else if(first==check[i]&&flag==0){
            firstindex = i-4000;
            flag=1;
        }
    }
    printf("%d\n",firstindex);
    printf("%d", large-small);
    return 0;
}
