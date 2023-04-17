#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int p[10];
int maxs;
int low = 2134567890;
vector<int>final;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		if (i == 0)continue;
		if (low >= p[i]) {
			num = i;
			low = p[i];
		}
	}
	cin >> m;
	maxs = m / low;
	if (maxs == 0)cout << 0;
	else {
		int k = m % low;
		maxs += k / p[0];
		int two_max = m - low;
		two_max = two_max / p[0];
		int check = 0;
		if (maxs == two_max + 1)check = 1;
		maxs = max(two_max + 1, maxs);

		if (p[0] < low)num = 0;
		for (int i = 0; i < maxs; i++) {
			final.push_back({ num });
		}
		m -= p[num] * maxs;
		k = 0;

		while (m > 0) {
			for (int i = n - 1; i >= 0; i--) {
				if (m - p[i] + p[num] >= 0) {
					final[k] = i;
					m += p[num];
					m -= p[i];
					break;
				}
			}
			k++;
			if (k == maxs)break;
		}

		for (int i = 0; i < maxs; i++) {
			cout << final[i];
		}
	}
}

