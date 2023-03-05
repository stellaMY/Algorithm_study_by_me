#include <iostream>
using namespace std;

int n, atk;
struct node {
	long long monster, matk, mh;
};
node dungeun[1234456];
long long maxhp;

int main() {
	cin >> n >> atk;
	for (int i = 0; i < n; i++) {
		long long monster, matk, mh;
		cin >> monster >> matk >> mh;
		dungeun[i] = { monster, matk, mh };
	}
	long long left = 0;
	long long right = 2134567892134567890;
	while (left <= right) {
		long long tempmax = (left+right)/2;
		long long tempatk = atk;
		int flag = 0;
		for (int i = 0; i < n; i++) {
			node now = dungeun[i];
			if (now.monster == 1) {
				int k = now.mh / tempatk;
				if (now.mh % tempatk == 0)k--;
				tempmax -= k * now.matk;
				if (tempmax <= 0) {
					flag = 1;
					break;
				}
			}
			else if (now.monster == 2) {
				tempatk += now.matk;
				tempmax += now.mh;
				if (tempmax > (left+right)/2)tempmax = (left + right) / 2;
			}
		}
		if (flag == 0) {
			maxhp = (left + right) / 2;
			right = (left + right) / 2 - 1;
		}
		else {
			left = (left + right) / 2+1;
		}
	}
	cout <<maxhp;
}
//22
//20
//17
//