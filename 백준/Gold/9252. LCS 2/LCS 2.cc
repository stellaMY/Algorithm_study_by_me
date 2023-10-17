#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string one, two;
int dp[1001][1001];
string answer;

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
	int i = one.size(); int j = two.size();
	while(i>0&&j>0){
		int ones = dp[i][j];
		int twos = dp[i - 1][j];
		int three = dp[i][j - 1];
		int four = dp[i - 1][j - 1];
		if (four == three && three == twos && four < ones) {
			answer += one[i-1];
			i--; j--;
		}
		else if (ones==twos&&twos>three) {
			i--;
		}
		else {
			j--;
		}
	}
	string answered;
	for (int i = answer.size() - 1; i >= 0; i--) {
		answered += answer[i];
	}
	if (dp[one.size()][two.size()] != 0) {
		cout << dp[one.size()][two.size()] << "\n" << answered;
	}
	else cout << 0;
}