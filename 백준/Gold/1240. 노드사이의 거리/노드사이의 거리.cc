#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
struct node {
	int to, cost;
};
vector<node>v[1001];
int flag;

void gogo(int from, int to) {
	queue<node>q;
	q.push({ from, 0 });
	int visited[1001] = { 0 };
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < v[now.to].size(); i++) {
			//if (visited[v[now.to][i].to] < visited[now.to] + v[now.to][i].cost)continue;
			if (visited[v[now.to][i].to] != 0)continue;
			visited[v[now.to][i].to] = visited[now.to] + v[now.to][i].cost;
			if (v[now.to][i].to == to) {
				cout << visited[now.to] + v[now.to][i].cost << "\n";
				flag = 1;
				return;
			}
			q.push({ v[now.to][i].to, visited[now.to] + v[now.to][i].cost });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		flag = 0;
		gogo(from, to);
	}
}