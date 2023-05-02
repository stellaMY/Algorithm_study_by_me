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

// 환승한 횟수와 비용을 가지고 지하철을 돌면서 환승을 한 횟수가 적다면 비용을 갱신하고
// 만약 같다면 확인하여 더 적은 비용으로 값 갱신
void gogo(int start) {
	priority_queue<node>q;
	q.push({ 0, 0, 0 , own_train[0] });
	while (!q.empty()) {
		node now = q.top();
		q.pop();
		// 도착지라면 
		if (now.now == m) {
			if (result_change < now.change)continue;
			if (result_cost > now.cost) {
				result_cost = now.cost;
				result_change = now.change;
			}
			continue;
		}
		for (int i = 0; i < n; i++) {
			// 연결이 안되어 있다면 패스
			if (train[now.now][i] == 0)continue;
			node tmp = now;
			// 만약 현재 열차와 다음 열차의 소유주가 다르다면 갈아탄 횟수 추가
			if (own_train[i] != now.train) {
				tmp.change++;
			}
			// 방문한적이 없는 역이라면 저장
			if (visited[i].cnt == 0 && visited[i].cost == 0) {
				visited[i].cnt = tmp.change;
				visited[i].cost = tmp.cost + train[tmp.now][i];
				q.push({ i, tmp.change, tmp.cost + train[tmp.now][i], own_train[i] });
			}
			// 방문한적이 있는 역이라면 갈아탄 횟수 확인후 
			// 더 많이 갈아 탔다면 패스, 같은 횟수라도 더 많은 비용이면 패스
			else {
				if (visited[i].cnt < tmp.change)continue;
				else if (visited[i].cnt == tmp.change) {
					if (visited[i].cost <= tmp.cost + train[tmp.now][i])continue;
				}
				visited[i].cnt = tmp.change;
				visited[i].cost = tmp.cost + train[tmp.now][i];
				q.push({ i, tmp.change,tmp.cost + train[tmp.now][i], own_train[i] });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	// 지하철 주인들을 저장
	for (int i = 0; i < n; i++) {
		cin >> own_train[i];
	}
	// 서로 연결되어 있는 지하철을 저장
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> train[i][j];
		}
	}
	visited[0].cost = -1;
	gogo(0);
	cout << result_change << " " << result_cost;
}