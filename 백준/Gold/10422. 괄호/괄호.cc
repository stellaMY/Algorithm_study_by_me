/*
{}
{}{} {{}}

{{}{}} {{}}{} {}{{}} {}{}{} 

앞에서에서 하나의 괄호가 더 생긴 것이다
이 괄호안에 어떻게 들어갈 것인가 
{}나머지 {하나}나머지 {두개}나머지 => 겹치는 것 제거

{}{}{} {}{{}} {{}}{} {{}{}} {{{}}} 

{}{}{}{} {}{}{{}} {}{{}}{} {}{{}{}} {}{{{}}} 
{{}}{}{}  {{}}{{}} {{}{}}{} {{{}}}{}
{{}{}{}} {{}{{}}} {{{}}{}} {{{}{}}} {{{{}}}
*/
#include <iostream>
using namespace std;

int n;
long long dp[5002];

int main() {
	dp[0] = 1;
	dp[2] = 1;
	dp[4] = 2;
	for (int i = 6; i < 5002; i+=2) {
		for (int j = 0; j < i; j += 2) {
			dp[i] += dp[j] * dp[i - j - 2];
			dp[i] = dp[i] % 1000000007;
		}
	}
	dp[0] = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}
}