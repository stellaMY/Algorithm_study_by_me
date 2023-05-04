#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int dp[1001][1001];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int y, x;
		cin >> y >> x;
		if (x > y) {
			int tmp = y;
			y = x;
			x = tmp;
		}
		dp[y][x]++;
	}
	int answer = n;
	for (int i = 1; i < 1001; i++) {
		for (int j = 1; j < 1001; j++) {
			int kk = dp[i][j];
			dp[i][j] = max(dp[i - 1][j] + kk, dp[i][j]);
			dp[i][j] = max(dp[i][j - 1] + kk, dp[i][j]);
			dp[i][j] = max(dp[i - 1][j - 1] + kk, dp[i][j]);
		}
	}
	cout << dp[1000][1000];
}