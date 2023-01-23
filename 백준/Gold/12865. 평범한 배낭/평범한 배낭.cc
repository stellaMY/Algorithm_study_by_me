#include <iostream>
#include <cmath>
using namespace std;

int n, k;
struct node {
	int weight, price;
};
node bag[101];
int dp[101][100001];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int weight, price;
		cin >> weight >> price;
		bag[i] = { weight, price };
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= bag[i].weight) {
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j - bag[i].weight] + bag[i].price);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[n][k];
}