#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int math[1000001];
int low = 2134567890;
int cnt;
int final;
vector<int>last;
vector<int>now;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> math[i];
	}
	sort(math, math + n);
	int flag;
	if (n > 500)cout << -1;
	else {
		for (int i = math[1]; i >= 1; i--) {
			cnt = 0;
			for (int j = 0; j < n; j++) {
				if (math[j] % i == 0)cnt++;
				else final = math[j];
			}
			if (cnt == n) {
				flag = 1;
				cout << -1;
				break;
			}
			if (cnt == n - 1) {
				cout << i << " " << final;
				break;
			}
		}
	}
}