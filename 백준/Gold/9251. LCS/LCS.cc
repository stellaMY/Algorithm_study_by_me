#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string one, two;
int dp[1001][1001];

int main() {
	cin >> one >> two;
	for (int i = 1; i <= one.size(); i++) {
		for (int j = 1; j <= two.size(); j++) {
			if (one[i - 1] == two[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	cout << dp[one.size()][two.size()];
}