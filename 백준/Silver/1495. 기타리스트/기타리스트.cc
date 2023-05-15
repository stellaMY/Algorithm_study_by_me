#include <iostream>
using namespace std;

int dp[51][1002];
int play[51];
int n, s, m;
int answer = 0;
int flag = 0;

int gogo(int now, int volume) {
	if (now == n) {
		flag = 2;
		if (answer < volume)answer = volume;
		return volume;
	}
	else if (dp[now][volume] != 0) return dp[now][volume];
	else {
		if (volume + play[now] <= m) {
			dp[now][volume] = max(dp[now][volume], gogo(now + 1, volume + play[now]));
		}
		if (volume - play[now] >= 0) {
			dp[now][volume] = max(dp[now][volume], gogo(now + 1, volume - play[now]));
		}
		if (volume + play[now] > m && volume - play[now] < 0)dp[now][volume]=2134567890;
		return dp[now][volume];
	}
}

int main() {
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> play[i];
	}
	gogo(0, s);
	if (s > m)answer = 0;
	if (answer==0 && flag==0)cout << -1;
	else cout << answer;
}