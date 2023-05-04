#include <iostream>
#include <cmath>
using namespace std;

int dp[102][102];
int n, m;
int nday[102];

int buy(int day, int coupon) {
	if (day > n) return 0;
	else if (dp[day][coupon] != 2134567890)return dp[day][coupon];
	else if (nday[day] == 1)return buy(day + 1, coupon);
	else {
		int now = dp[day][coupon];
		now = min(now, buy(day + 1, coupon) + 10000);
		now = min(now, buy(day + 3, coupon+1) + 25000);
		now = min(now, buy(day + 5, coupon + 2) + 37000);
		if (coupon >= 3)now = min(now, buy(day + 1, coupon - 3));
		dp[day][coupon] = now;
		return dp[day][coupon];
	}
}

int main() {
	cin >> n>> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		nday[num] = 1;
	}
	for (int i = 1; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			dp[i][j] = 2134567890;
		}
	}
	buy(1, 0);
	int answer = 2134567890;
	for (int i = 0; i < n; i++) {
		answer = min(answer, dp[1][i]);
	}
	cout << answer;
}