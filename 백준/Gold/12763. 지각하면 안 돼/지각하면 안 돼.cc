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
edge visited[101];
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
			// 만약에 내가 가려는 곳이 도착지라면
			if (building[now.now][i].to == n) {
				// 여기까지의 시간이 주어진 시간 이상이다 패스
				// 여기까지의 가격이 주어진 가격 이상이다 패스
				if (now.time + building[now.now][i].time > t)continue;
				if (now.cost + building[now.now][i].cost > m)continue;
				// 다른 경로의 결과보다 더 적은 가격이다 => 정답 갱신 
				if (result > now.cost + building[now.now][i].cost)result = building[now.now][i].cost + now.cost;
			}
			// 도착지가 아니라면
			else {
				// 여기까지의 시간이 주어진 시간 이상이다 패스
				// 여기까지의 가격이 주어진 가격 이상이다 패스
				if (now.time + building[now.now][i].time >= t)continue;
				if (now.cost + building[now.now][i].cost >= m)continue;
				// 이미 같은 시간을 가지고 방문을 하였는데 가져온 가격이 그 때보다 크다면 패스
				if (visited[building[now.now][i].to].time == now.time + building[now.now][i].time) {
					if (visited[building[now.now][i].to].cost >= now.cost + building[now.now][i].cost)continue;
				}
				// 내가 가장 작은 시간과 비용의 조합으로 현재의 위치에 왔으므로 visited 갱신 후
				// 도착지로 향하기 위해서 pq에 넣고 다시 탐색
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
