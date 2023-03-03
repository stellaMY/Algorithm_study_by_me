#include <iostream>
using namespace std;

int n;
long long dp[6][1001];
long long final;

int main() {
	cin >> n;
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[2][0] = 0;
	dp[3][0] = 1;
	dp[4][0] = 0;
	dp[5][0] = 0;

	dp[0][1] = 2;
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[3][1] = 3;
	dp[4][1] = 1;
	dp[5][1] = 0;

	for (int i = 2; i < n; i++) {
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1] +dp[2][i-1];
		dp[1][i] = dp[0][i - 1];
		dp[2][i] = dp[1][i - 1];
		dp[3][i] = dp[0][i - 1] + dp[1][i - 1] + dp[3][i-1] + dp[2][i-1] + dp[5][i-1] + dp[4][i - 1];
		dp[4][i] = dp[3][i - 1];
		dp[5][i] = dp[4][i - 1];
		for (int j = 0; j < 6; j++) {
			dp[j][i] = dp[j][i] % 1000000;
		}
	}
	for (int i = 0; i < 6; i++) {
		dp[i][n - 1] = dp[i][n - 1] % 1000000;
		final += dp[i][n - 1];
		final = final % 1000000;
	}
	cout << final;
}