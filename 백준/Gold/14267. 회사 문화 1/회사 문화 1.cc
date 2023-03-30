#include <iostream>
using namespace std;

int n, m;
int dp[100001][3];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == -1)continue;
		else dp[i + 1][0] = num;
	}
	for (int i = 0; i < m; i++) {
		int one, two;
		cin >> one >> two;
		dp[one][1] += two;
	}
	cout << 0 << " ";
	for (int i = 1; i < n; i++) {
		int up = dp[i + 1][0];
		cout << dp[up][2] + dp[i + 1][1] << " ";
		dp[i + 1][2] = dp[up][2] + dp[i + 1][1];
	}
}