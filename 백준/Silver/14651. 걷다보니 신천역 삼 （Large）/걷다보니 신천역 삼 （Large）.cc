#include <iostream>
using namespace std;

long long dp[33334];

/*
3의 배수 = 각 자리수 더했을 때 3의 배수
각 갯수별로 나누어지는 갯수를 추가
나머지가 0이면 0을 더하면 나머지 0 1이면 2를 더하면 0 이런식으로
나머지가 0인 아이만 답
*/

int main() {
	int n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i-1] * 3 % 1000000009;
	}
	cout << dp[n] % 1000000009;
}