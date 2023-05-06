#include <iostream>
using namespace std;

int n;
// 각 수별로 앞자리를 넘겨가면서 저장 10에는 최종 결과를 저장
long long dp[11][1001];

int main() {
	cin >> n;
	// 한 자리는 모두 하나
	for (int i = 0; i < 10; i++) {
		dp[i][1] = 1;
	}
	dp[10][1] = 10;
	for (int i = 2; i < 1001; i++) {
		// 0 뒤에는 전체가 올 수 있다
		int final = dp[10][i-1];
		dp[0][i] = final;
		// 이번 자릿수의 최종 결과가 될 값
		int nowfinal = dp[0][i];
		for (int j = 1; j < 10; j++){
			// j 뒤에는 앞선 자릿수에서 j보다 작은 수를 값을 빼고 넣어준다
			dp[j][i] = final - dp[j - 1][i - 1];
			final -= dp[j - 1][i - 1];
			nowfinal += dp[j][i];
		}
		dp[10][i] = nowfinal;
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cout << dp[10][num] << "\n";
	}
}
