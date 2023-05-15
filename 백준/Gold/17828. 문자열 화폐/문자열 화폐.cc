#include <iostream>
#include <queue>
using namespace std;

int n, x;
int cnt;
int flag;

int main() {
	cin >> n >> x;
	string str;
	for (int i = 0; i < n; i++) {
		str += 'A';
	}
	cnt = n;
	int now = n - 1;
	if (cnt == x)flag = 1;
	while (cnt <= x && flag==0) {
		for (int i = 1; i < 26; i++) {
			str[now] += 1;
			cnt++;
			if (cnt == x) {
				flag = 1;
				break;
			}
		}
		now--;
		if (now < 0)break;
	}
	if (flag == 0)cout << "!";
	else cout << str;
}