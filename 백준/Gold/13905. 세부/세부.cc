#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, s, e, flag;
struct node {
	int from, to, cost;
};
priority_queue<node>island;
int final;
int visited[100001];

bool operator<(node a, node b) {
	if (a.cost > b.cost)return false;
	if (a.cost < b.cost)return true;
	return false;
}

int parent[100001];

int Find(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = Find(parent[node]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb)
		return;
	parent[pb] = pa;
}

//void gold(int from, int to) {
//	while (!island.empty()) {
//		node now = island.top();
//		island.pop();
//		final = now.cost;
//		visited[now.from] = 1;
//		visited[now.to] = 1;
//		if (visited[from] == 1 && visited[to] == 1)return;
//	}
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> s >> e;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		island.push({ from, to, cost });
	}
	for (int i = 0; i < m; i++) {
		node now = island.top();
		island.pop();
		Union(now.from, now.to);
		if (Find(s) == Find(e)) {
			cout << now.cost;
			flag = 1;
			break;
		}
	}
	if (flag == 0)cout << 0;
	//cout << final;
}