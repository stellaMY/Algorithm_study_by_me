#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[100001][3];
int dp[100001][3];

int main() {
	int flag = 1;
	int num = 0;
	cin >> n;
	while (flag == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
			}
		}
		num++;
		dp[0][0] = 2134567890;
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][1] + arr[0][2];
		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][0] + arr[i][0], dp[i - 1][1] + arr[i][0]);
			dp[i][1] = min(dp[i - 1][0] + arr[i][1], dp[i - 1][1] + arr[i][1]);
			dp[i][1] = min(dp[i][1], dp[i - 1][2] + arr[i][1]);
			dp[i][1] = min(dp[i][1], dp[i][0] + arr[i][1]);
			dp[i][2] = min(dp[i - 1][1] + arr[i][2], dp[i - 1][2] + arr[i][2]);
			dp[i][2] = min(dp[i][1] + arr[i][2], dp[i][2]);
		}
		dp[n - 1][1] = min(dp[n - 1][0] + arr[n - 1][1], dp[n - 1][1]);
		cout << num << ". " << dp[n-1][1] << "\n";
		cin >> n;
		if (n == 0)flag = 0;
	}
}