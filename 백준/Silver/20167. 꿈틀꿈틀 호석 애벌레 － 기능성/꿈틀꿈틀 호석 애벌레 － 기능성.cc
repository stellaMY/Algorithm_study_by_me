#include<iostream>
using namespace std;

int n, k;
int cata[21];
struct node {
	int get, finish;
};
node getget[21];
int dp[21];
int eaten;
int answer = 0;

void dfs(int now) {
	if (now >= n) {
		if (answer < eaten)answer = eaten;
		return;
	}
	for (int i = now; i < n; i++) {
		eaten += getget[i].get;
		dfs(getget[i].finish + 1);
		eaten -= getget[i].get;
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> cata[i];
	}

	for (int i = 0; i < n; i++) {
		int get = cata[i];
		if (get >= k) {
			getget[i] = { get - k, i };
			continue;
		}
		if (i == n - 1) {
			getget[i] = { 0, n - 1 };
		}
		for (int j = i + 1; j < n; j++) {
			get += cata[j];
			if (get >= k) {
				getget[i] = { get - k, j };
				break;
			}
			if (j == n - 1) {
				getget[i] = { 0, n - 1 };
			}
		}
	}

	for (int i = 0; i < n; i++) {
		eaten = getget[i].get;
		dfs(getget[i].finish+1);
	}
	cout << answer;
}