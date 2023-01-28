#include <iostream>
using namespace std;

int a[3];
int b[3];
int c[3];

int main(){
    for(int i =0; i<2; i++){
        for(int j =0; j<3; j++){
            if(i==0)cin>>a[j];
            else cin>>b[j];
        }
    }
    c[0]=b[0]-a[2];
    c[1] = b[1]/a[1];
    c[2]=b[2]-a[0];
    for(int i =0; i<3; i++){
        cout << c[i]<<" ";
    }
}