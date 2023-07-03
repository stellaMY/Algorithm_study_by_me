#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n;
int dp[1001][3];
int home[1001][3];
int answer=2134568790;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> home[i + 1][j];
		}
	}
	for (int j = 0; j < 3; j++) {
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 3; i++) {
			dp[1][i] = 2134567890;
		}
		dp[1][j] = home[1][j];
		for (int i = 2; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][1] + home[i][0], dp[i - 1][2] + home[i][0]);
			dp[i][1] = min(dp[i - 1][0] + home[i][1], dp[i - 1][2] + home[i][1]);
			dp[i][2] = min(dp[i - 1][1] + home[i][2], dp[i - 1][0] + home[i][2]);
		}
		for (int i = 0; i < 3; i++) {
			if (i == j)continue;
			answer = min(dp[n][i], answer);
		}
	}
	cout << answer;
	return 0;
}