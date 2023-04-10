#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int own_train[1001];
int train[1001][1001];
struct node {
	int now, change, cost, train;
};
struct edge {
	int cnt, cost;
};
edge visited[1001];
int result_change = 2134567890;
int result_cost = 2134567890;
bool operator<(node a, node b) {
	if (a.change > b.change)return true;
	if (a.change < b.change)return false;
	if (a.cost > b.cost)return true;
	if (a.cost < b.cost)return false;
	return false;
}


void gogo(int start) {
	priority_queue<node>q;
	q.push({ 0, 0, 0 , own_train[0] });
	while (!q.empty()) {
		node now = q.top();
		q.pop();
		if (now.now == m) {
			if (result_change < now.change)continue;
			if (result_cost > now.cost) {
				result_cost = now.cost;
				result_change = now.change;
			}
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (train[now.now][i] == 0)continue;
			if (own_train[i] != now.train) {
				if (visited[i].cnt == 0 && visited[i].cost == 0) {
					visited[i].cnt = now.change + 1;
					visited[i].cost = now.cost + train[now.now][i];
					q.push({ i, now.change + 1, now.cost + train[now.now][i], own_train[i] });
				}
				else {
					if (visited[i].cnt < now.change + 1)continue;
					else if (visited[i].cnt == now.change + 1) {
						if (visited[i].cost <= now.cost + train[now.now][i])continue;
					}
					visited[i].cnt = now.change + 1;
					visited[i].cost = now.cost + train[now.now][i];
					q.push({ i, now.change + 1, now.cost + train[now.now][i], own_train[i] });
				}
			}
			else {
				if (visited[i].cnt == 0 && visited[i].cost == 0) {
					visited[i].cnt = now.change;
					visited[i].cost = now.cost + train[now.now][i];
					q.push({ i, now.change, now.cost + train[now.now][i], own_train[i] });
				}
				else {
					if (visited[i].cnt < now.change)continue;
					else if (visited[i].cnt == now.change) {
						if (visited[i].cost <= now.cost + train[now.now][i])continue;
					}
					visited[i].cnt = now.change;
					visited[i].cost = now.cost + train[now.now][i];
					q.push({ i, now.change, now.cost + train[now.now][i], own_train[i] });
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> own_train[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> train[i][j];
		}
	}
	visited[0].cost = -1;
	gogo(0);
	cout << result_change << " " << result_cost;
}

/*
6 3
0
1
1
0
1
0
0 3 1 0 10 0
3 0 0 15 0 0
1 0 0 8 0 1
0 15 0 0 10 0
10 0 0 10 0 1
0 0 1 0 1 0
*/