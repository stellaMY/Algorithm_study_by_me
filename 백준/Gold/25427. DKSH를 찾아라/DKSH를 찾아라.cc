#include<iostream>
using namespace std;

int dp[4][100001];

int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	if (str[0] == 'D') {
		dp[0][0] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (str[i] == 'D') {
			dp[0][i] = dp[0][i - 1] + 1;
			dp[1][i] = dp[1][i - 1];
			dp[2][i] = dp[2][i - 1];
			dp[3][i] = dp[3][i - 1];
		}
		else if (str[i] == 'K') {
			dp[0][i] = dp[0][i - 1];
			dp[1][i] = dp[1][i - 1] + dp[0][i-1];
			dp[2][i] = dp[2][i - 1];
			dp[3][i] = dp[3][i - 1];
		}
		else if (str[i] == 'S') {
			dp[0][i] = dp[0][i - 1];
			dp[1][i] = dp[1][i - 1];
			dp[2][i] = dp[2][i - 1]+ dp[1][i - 1];
			dp[3][i] = dp[3][i - 1];
		}
		else if (str[i] == 'H') {
			dp[0][i] = dp[0][i - 1];
			dp[1][i] = dp[1][i - 1];
			dp[2][i] = dp[2][i - 1];
			dp[3][i] = dp[3][i - 1]+ dp[2][i - 1];
		}
		else {
			dp[0][i] = dp[0][i - 1];
			dp[1][i] = dp[1][i - 1];
			dp[2][i] = dp[2][i - 1];
			dp[3][i] = dp[3][i - 1];
		}
	}
	cout << dp[3][n - 1];
}