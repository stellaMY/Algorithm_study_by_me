#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, m, ji, sung;
struct node {
	int to, cost;
};
vector<node>map[101];
int jivisited[101];
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
	for (int i = 0; i <= v; i++) {
		jivisited[i] = 2134567890;
		sungvisited[i] = 2134567890;
	}
	cin >> ji >> sung;
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
	int final = 2134567890;
	int finalfromji = 2134657890;
	int place = 0;
	for (int i = 1; i <= v; i++) {
		if (i == ji || i == sung)continue;
		if (jivisited[i] == 2134567890 || sungvisited[i] == 2134567890)continue;
		if (final > jivisited[i] + sungvisited[i]) {
			final = jivisited[i] + sungvisited[i];
			if (jivisited[i] > sungvisited[i]) {
				finalfromji = 2134567890;
				place = 0;
				continue;
			}
			finalfromji = jivisited[i];
			place = i;
		}
		else if (final == jivisited[i] + sungvisited[i]) {
			if (jivisited[i] > sungvisited[i])continue;
			if (finalfromji > jivisited[i]) {
				finalfromji = jivisited[i];
				place = i;
			}
		}
	}
	if (place == 0)cout << -1;
	else cout << place;
}