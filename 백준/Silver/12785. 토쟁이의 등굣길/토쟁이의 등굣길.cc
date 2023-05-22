#include <iostream>
using namespace std;

long long w, h;
long long x, y;
long long dp[201][201];
long long dp2[221][221];

int main() {
	cin >> w >> h >> x >> y;
	dp[1][1] = 1;
	for (int i = 0; i <= h; i++) {
		dp2[i][1] = 1;
	}
	for (int i = 0; i <= w ; i++) {
		dp2[1][i] = 1;
	}
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (i == 1 && j == 1)continue;
			dp[i - 1][j] = dp[i - 1][j] % 1000007;
			dp[i][j - 1] = dp[i][j - 1] % 1000007;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] = dp[i][j] % 1000007;
		}
	}
	long long answer = dp[y][x];
	answer = answer % 1000007;
	dp2[0][0] = 1;
	for (int i = 0; i <= h; i++) {
		dp2[i][1] = 1;
	}
	for (int i = 0; i <= w; i++) {
		dp2[1][i] = 1;
	}
	for (int i = 1; i <= h-y+1; i++) {
		for (int j = 1; j <= w-x+1; j++) {
			if (i == 1 && j == 1)continue;
			dp2[i - 1][j] = dp2[i - 1][j] % 1000007;
			dp2[i][j - 1] = dp2[i][j - 1] % 1000007;
			dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1];
			dp2[i][j] = dp2[i][j] % 1000007;
		}
	}
	if (dp2[h - y+1][w - x+1] != 0) {
		dp2[h - y+1][w - x+1] %= 1000007;
		answer *= dp2[h - y+1][w - x+1];
	}
	answer = answer % 1000007;
	cout << answer;
}