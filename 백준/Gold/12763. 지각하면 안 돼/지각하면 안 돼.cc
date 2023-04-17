#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
struct node {
	int to, time, cost;
};
vector<node>building[101];
int t, m;
struct edge {
	int now, cost, time;
};
edge visited[101];
bool operator < (edge a, edge b) {
	if (a.time > b.time)return true;
	if (a.time < b.time)return false;
	if (a.cost > b.cost)return true;
	if (a.cost < b.cost)return false;
	return false;
}
int result=2134567890;

void taxi(int start) {
	priority_queue<edge>q;
	q.push({ 1, 0, 0 });
	while (!q.empty()) {
		edge now = q.top();
		q.pop();
		for (int i = 0; i < building[now.now].size(); i++) {
			if (building[now.now][i].to == n) {
				if (now.time + building[now.now][i].time > t)continue;
				if (now.cost + building[now.now][i].cost > m)continue;
				if (result > now.cost + building[now.now][i].cost)result = building[now.now][i].cost + now.cost;
			}
			else {
				if (now.time + building[now.now][i].time >= t)continue;
				if (now.cost + building[now.now][i].cost >= m)continue;
				if (visited[building[now.now][i].to].time == now.time + building[now.now][i].time) {
					if (visited[building[now.now][i].to].cost >= now.cost + building[now.now][i].cost)continue;
				}
				if (visited[building[now.now][i].to].cost == now.cost + building[now.now][i].cost) {
					if (visited[building[now.now][i].to].time >= now.time + building[now.now][i].time)continue;
				}
				visited[building[now.now][i].to] = { 0, now.cost + building[now.now][i].cost, now.time + building[now.now][i].time };
				q.push({ building[now.now][i].to ,  now.cost + building[now.now][i].cost, now.time + building[now.now][i].time });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> t >> m;
	int road;
	cin >> road;
	for (int i = 0; i < road; i++) {
		int to, from, time, cost;
		cin >> to >> from >> time >> cost;
		building[to].push_back({ from, time, cost });
		building[from].push_back({ to, time, cost });
	}
	taxi(1);
	if (result == 2134567890)cout << -1;
	else cout << result;
}