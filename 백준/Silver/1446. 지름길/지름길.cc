#include <iostream>
#include <vector>
using namespace std;

int n, m;
struct node {
	int f, cost;
};
vector<int>exist[10001];
int dp[10001];
vector<node>shorts;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int s, f, cost;
		cin >> s >> f >> cost;
		exist[s].push_back(shorts.size());
		shorts.push_back({ f, cost });
	}
	for (int i = 0; i <= m; i++) {
		dp[i] = 2134567890;
	}
	dp[0] = 0;
	for (int i = 0; i <= m; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		for (int j = 0; j < exist[i].size(); j++) {
			dp[shorts[exist[i][j]].f] = min(dp[shorts[exist[i][j]].f], dp[i] + shorts[exist[i][j]].cost);
		}
	}
	cout << dp[m];
}