#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, m, ji, sung;
struct node {
	int to, cost;
};
vector<node>map[101];
// 지헌이가 갈 수 있는 도착지들의 최소값 저장
int jivisited[101];
// 성하가 갈 수 있는 도착지들의 최솟값 저장
int sungvisited[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		map[from].push_back({ to, cost });
		map[to].push_back({ from, cost });
	}
    // 각각 int 최대값으로 갱신
	for (int i = 0; i <= v; i++) {
		jivisited[i] = 2134567890;
		sungvisited[i] = 2134567890;
	}
	cin >> ji >> sung;
    // 먼저 지헌이가 갈 수 있는 도착지 계산 
    // 기본 다익스트라
	queue<node>goji;
	goji.push({ ji, 0 });
	jivisited[ji] = 0;
	while (!goji.empty()) {
		node now = goji.front();
		goji.pop();
		for (int i = 0; i < map[now.to].size(); i++) {
			if (jivisited[map[now.to][i].to] <= now.cost + map[now.to][i].cost)continue;
			jivisited[map[now.to][i].to] = now.cost + map[now.to][i].cost;
			goji.push({ map[now.to][i].to,  now.cost + map[now.to][i].cost });
		}
	}
    // 먼저 성하가 갈 수 있는 도착지 계산 
    // 기본 다익스트라
	queue<node>gosung;
	gosung.push({ sung, 0 });
	sungvisited[sung] = 0;
	while (!gosung.empty()) {
		node now = gosung.front();
		gosung.pop();
		for (int i = 0; i < map[now.to].size(); i++) {
			if (sungvisited[map[now.to][i].to] <= now.cost + map[now.to][i].cost)continue;
			sungvisited[map[now.to][i].to] = now.cost + map[now.to][i].cost;
			gosung.push({ map[now.to][i].to,  now.cost + map[now.to][i].cost });
		}
	}
    // 최단 거리
	int final = 2134567890;
    // 최단 거리가 되는 도착지까지 지헌이의 거리
	int finalfromji = 2134657890;
    // 최단 거리가 되는 도착지 
	int place = 0;
	for (int i = 1; i <= v; i++) {
        // 둘의 시작지라면 패스
		if (i == ji || i == sung)continue;
        // 둘 중 하나라도 가지 못한다면 패스
		if (jivisited[i] == 2134567890 || sungvisited[i] == 2134567890)continue;
        // 최단 거리가 더 짧다면 다음 조건 확인
		if (final > jivisited[i] + sungvisited[i]) {
			final = jivisited[i] + sungvisited[i];
            // 만일 지헌이가 더 오래걸린다면
            // 그곳은 정답이 될 수 없다
            // 그렇다고 이전의 더 긴 거리를 가지는 도착지 또한 정답이 될 수 없으니 다시 처음으로 갱신한다
            // 하지만 최단 거리의 경우는 계속 비교를 해야하므로 갱신 하지 않는다
			if (jivisited[i] > sungvisited[i]) {
				finalfromji = 2134567890;
				place = 0;
				continue;
			}
            // 지헌이가 더 오래 걸리지 않는다면 모두 해당 값으로 갱신
			finalfromji = jivisited[i];
			place = i;
		}
        // 만약에 현재 최단 거리와 기록된 최단 거리가 같다면
		else if (final == jivisited[i] + sungvisited[i]) {
            // 지한이가 더 오래 걸리면 패스
			if (jivisited[i] > sungvisited[i])continue;
            // 기록된 지헌이 거리보다 현재의 지헌이 거리가 짧다면 갱신
            // 1번 도착지부터 확인하기 때문에 더 작은 값인지는 확인하지 않고 넘어가도 된다
			if (finalfromji > jivisited[i]) {
				finalfromji = jivisited[i];
				place = i;
			}
		}
	}
    // 갱신이 안된다면 도착지가 0이므로 -1
    // 아니라면 그 값을 출력한다
	if (place == 0)cout << -1;
	else cout << place;
}
