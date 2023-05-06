#include <iostream>
using namespace std;

int n;
long long dp[11][1001];

int main() {
	cin >> n;
	for (int i = 0; i < 10; i++) {
		dp[i][1] = 1;
	}
	dp[10][1] = 10;
	for (int i = 2; i < 1001; i++) {
		long long final = dp[10][i-1];
		dp[0][i] = final;
		long long nowfinal = dp[0][i];
		for (int j = 1; j < 10; j++){
			dp[j][i] = final - dp[j - 1][i - 1];
			final -= dp[j - 1][i - 1];
			nowfinal += dp[j][i];
		}
		dp[10][i] = nowfinal;
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cout << dp[10][num] << "\n";
	}
}