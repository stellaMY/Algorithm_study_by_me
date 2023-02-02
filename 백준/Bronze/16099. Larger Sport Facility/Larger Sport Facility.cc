#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i =0; i<t; i++){
        long long l, w, ll, ww;
        cin >> l>>w>>ll>>ww;
        if(l*w>ll*ww)cout << "TelecomParisTech"<<"\n";
        else if(l*w<ll*ww)cout <<"Eurecom"<<"\n";
        else cout <<"Tie"<<"\n";
    }
}