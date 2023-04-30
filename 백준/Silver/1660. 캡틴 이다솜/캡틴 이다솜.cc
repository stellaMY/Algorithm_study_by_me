#include <iostream>
#include <cmath>
using namespace std;

// n개를 기준으로 각 갯수마다 가장 작을 수 있는 횟수 확인
int n, k;
// 확인결과 121개가 최대
long long triangle[130];
long long bomb[130];
long long dp[300001];

int main() {
	cin >> n;
	bomb[1] = 1;
	triangle[1] = 1;
	// 총 bomb의 갯수 계산
	// triangle에 더해질 triangle의 갯수 넣고 더하기
	// 만일 이미 주어진 갯수보다 커지면 스톱
	for (int i = 2; i <= 130; i++) {
		triangle[i] = triangle[i - 1] + i;
		bomb[i] = bomb[i - 1] + triangle[i];
		if (bomb[i] >= n) {
			k = i;
			break;
		}
	}
	// n까지 만들수 있는 횟수 확인
	// 3중으로 이전의 모든 값을 다 보면 시간 초과
	// 갯수로 보면서 그 차이만큼의 앞의 디피 값과 비교
	// 만일 갯수가 i보다 커지면 그대로 종료
	// 1개로 무조건 만들 수 있으니 처음 dp[i]= i
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j <= k; j++) {
			if (bomb[j] > i)break;
			dp[i] = min(dp[i - bomb[j]] + 1, dp[i]);
		}
	}
	cout << dp[n];
}