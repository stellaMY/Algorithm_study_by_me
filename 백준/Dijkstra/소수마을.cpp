#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int x, y, xx, yy,n;
struct node {
	int y, x;
};
struct edge {
	int to, cost;
};
vector<edge>v[4001];
node location[4005];
int visited[4001];
int num[9001];
bool operator < (edge a, edge b) {
	if (a.cost < b.cost)return false;
	if (a.cost > b.cost)return true;
	return false;
}

void dijk(int st, int fi) {
	priority_queue<edge>q;
	q.push({ st, 0 });
	while (!q.empty()) {
		edge now = q.top();
		q.pop();
		for (int i = 0; i < v[now.to].size(); i++) {
			if (num[v[now.to][i].cost] == 0)continue;
			if (visited[v[now.to][i].to] < v[now.to][i].cost + now.cost)continue;
			visited[v[now.to][i].to] = v[now.to][i].cost + now.cost;
			q.push({ v[now.to][i].to, visited[v[now.to][i].to] });
		}
	}
}

int main() {
	cin >> x >> y >> xx >> yy >> n;
	for (int i = 2; i <= 9000; i++) {
		int flag = 0;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)num[i] = 1;
	}
	location[0] = { y, x };
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		location[i] = { y, x };
	}
	location[n + 1] = { yy, xx };
	for (int i = 0; i <= n+1; i++) {
		visited[i] = 2134567890;
		for (int j = 0; j <= n + 1; j++) {
			if (i == j)continue;
			int k = sqrt((location[i].y - location[j].y) * (location[i].y - location[j].y) + (location[i].x - location[j].x) * (location[i].x - location[j].x));
			if (num[k] == 0)continue;
			v[i].push_back({ j, k });
			v[j].push_back({ i, k });
		}
	}
	dijk(0, n + 1);
	if (visited[n + 1] == 2134567890)cout << -1;
	else cout << visited[n + 1];
}
