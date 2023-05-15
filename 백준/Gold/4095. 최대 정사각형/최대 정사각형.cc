#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int n, m;
int map[1005][1005];
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> n >> m;
		int answer = 0;
		if (n == 0 && m==0)break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 1) {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
					dp[i][j] += map[i][j];
				}
				answer = max(answer, dp[i][j]);
			}
		}
		cout << answer<<"\n";
		memset(dp, 0,sizeof(dp));
		memset(map, 0, sizeof(map));
	}
}