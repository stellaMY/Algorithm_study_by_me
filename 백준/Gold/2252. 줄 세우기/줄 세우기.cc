#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int flag[33000];
vector<int>line[33000];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int f, b;
		cin >> f >> b;
		line[f].push_back(b);
		flag[b]++;
	}
	queue<int>q;
	queue<int>final;
	for (int i = 0; i < n; i++) {
		if (flag[i + 1] == 0) {
			q.push(i + 1);
			final.push(i + 1);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < line[now].size(); i++) {
			if (flag[line[now][i]] == 1) {
				q.push(line[now][i]);
				final.push(line[now][i]);
			}
			else flag[line[now][i]]--;
		}
	}
	while (!final.empty()) {
		cout << final.front()<<" ";
		final.pop();
	}
}