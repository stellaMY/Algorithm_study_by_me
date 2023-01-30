#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int tree[1001];
int dp[1001][2][32];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
	if (tree[0] == 1) {
		dp[0][0][0] = 1;
		dp[0][1][0] = 0;
	}
	else {
		dp[0][0][0] = 0;
		dp[0][1][1] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if(j!=0&&dp[i-1][0][j]==0&&dp[i-1][1][j]==0&& dp[i - 1][0][j-1] == 0 && dp[i - 1][1][j-1] == 0)continue;
			if (j == 0) {
				if (tree[i] == 1) {
					dp[i][0][j] = max(dp[i - 1][0][j] + 1,0);
					dp[i][1][j] = max(0, dp[i - 1][1][j]);
				}
				else if (tree[i] == 2) {
					dp[i][0][j] = max(dp[i - 1][0][j], 0);
					dp[i][1][j] = max(0, dp[i - 1][1][j] + 1);
				}
			}
			else {
				if (tree[i] == 1) {
					dp[i][0][j] = max(dp[i - 1][0][j] + 1, dp[i - 1][1][j - 1] + 1);
					dp[i][1][j] = max(dp[i - 1][0][j - 1], dp[i - 1][1][j]);
				}
				else if (tree[i] == 2) {
					dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j - 1]);
					dp[i][1][j] = max(dp[i - 1][0][j - 1] + 1, dp[i - 1][1][j] + 1);
				}
			}
		}
	}
	int final = 0;
	for (int i = 0; i <= m; i++) {
		final = max(final, dp[n - 1][0][i]);
		final = max(final, dp[n - 1][1][i]);
	}
	cout << final;
}
