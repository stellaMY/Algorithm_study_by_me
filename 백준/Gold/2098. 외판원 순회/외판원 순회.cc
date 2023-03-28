#include <iostream>
#include <cmath>
using namespace std;

int n;
long long tsp[20][20];
long long finish;
int dp[20][65540];

int TSP(int last, int visited) {
	if (visited + 1 == finish) {
		if (tsp[last][0] == 0)return 2134567890;
		else return tsp[last][0];
	}
	if (dp[last][visited] != 0)return dp[last][visited];
	long long tmp = 2134567890;
	for (int i = 0; i < n; i++) {
		if ((visited & (1 << i)) == 0 && tsp[last][i] != 0) {
			tmp = min(tmp, TSP(i, visited | 1 << i) + tsp[last][i]);
		}
	}
	dp[last][visited] = tmp;
	return tmp;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tsp[i][j];
		}
	}
	finish = pow(2, n);
	cout << TSP(0, 1 << 0);
}