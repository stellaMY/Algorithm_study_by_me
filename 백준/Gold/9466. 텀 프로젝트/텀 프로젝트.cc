#include <iostream>
using namespace std;

int visited[100002];
int finish[100002];
int student[100002];
int cnt;

void dfs(int origin) {
	visited[origin] = 1;
	int next = student[origin];
	if (visited[next] == 0) {
		dfs(next);
	}
	else if (finish[next]!=1) {
		for (int i = next; i != origin; i = student[i]) {
			cnt++;
		}
		cnt++;
	}
	finish[origin] = 1;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cnt = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> student[i+1];
		}
		for (int i = 0; i < n; i++) {
			if (visited[i+1]==1)continue;
			dfs(i+1);
		}
		for (int i = 0; i < n; i++) {
			finish[i + 1] = 0;
			visited[i + 1] = 0;
		}
		cout << n-cnt << "\n";
	}
}