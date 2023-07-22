#include <stdio.h>

float large=0;
float arr[1001];
float answer;

int main()
{
    int t;
    scanf("%d", &t);
    for(int i =0; i<t; i++){
        float num;
        scanf("%f", &num);
        arr[i]=num;
        if(num>large)large=num;
    }
    for(int i =0; i<t; i++){
        arr[i] = arr[i]/large*100;
        answer += arr[i];
    }
    printf("%f", answer/t);
}