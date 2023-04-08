#include <iostream>
using namespace std;

int alpha[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int dp[4001][4001];
int final;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string him;
	cin >> him;
	int flag = 0;
	for (int i = 0; i < him.size() / 2; i++) {
		if (him[i] != him[him.size() - 1 - i]) {
			flag = 1;
			cout << him.size();
			break;
		}
	}
	if (flag == 0) {
		string her = him.substr(0, him.size() - 1);
		for (int i = 0; i < her.size() / 2; i++) {
			if (her[i] != her[her.size() - 1 - i]) {
				flag = 1;
				cout << her.size();
				break;
			}
		}
	}
	if (flag == 0)cout << -1;
}