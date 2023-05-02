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
// 현재 위치와 가격, 시간을 알아야 한다
struct edge {
	int now, cost, time;
};
// 우선 시간내에 도착하는 것이 목표이고 그 이후에 더 작은 가격을 
// 찾는 것이므로 더 적은 시간을 기준으로 정렬후, 더 적은 가격으로 정렬
bool operator < (edge a, edge b) {
	if (a.time > b.time)return true;
	if (a.time < b.time)return false;
	if (a.cost > b.cost)return true;
	if (a.cost < b.cost)return false;
	return false;
}
int result = 2134567890;

void taxi(int start) {
	// pq로 시간을 줄여줍니다
	priority_queue<edge>q;
	q.push({ 1, 0, 0 });
	while (!q.empty()) {
		edge now = q.top();
		q.pop();
		for (int i = 0; i < building[now.now].size(); i++) {
			// 주어진 시간과 돈이 넘어가면 패스
			if (now.time + building[now.now][i].time > t)continue;
			if (now.cost + building[now.now][i].cost > m)continue;
			// n 이면 확인하고 갱신
			if (building[now.now][i].to == n && result > now.cost + building[now.now][i].cost)result = building[now.now][i].cost + now.cost;
			// 아니면 넣기
			else {
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
		// 현재의 빌딩에서 다음 빌딩으로 갈때 발생하는 시간과 비용을 넣어준다
		// 도로는 양방향이므로 to, from 모두 넣어준다
		building[to].push_back({ from, time, cost });
		building[from].push_back({ to, time, cost });
	}
	taxi(1);
	// 갱신되지 않았다는 말은 도착하지 못한다는 말이니까 -1
	if (result == 2134567890)cout << -1;
	else cout << result;
}
