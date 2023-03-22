#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int>dducks[1001];
int visited[1001][10];
vector<int>path;
int flag;

void dfs(int now) {
	if (flag == 1)return;
	if (now == n) {
		for (int i = 0; i < n; i++) {
			cout << path[i] << "\n";
		}
		flag = 1;
		return;
	}
	for (int i = 0; i < dducks[now].size(); i++) {
		//if (dducks[now][i] == 0)continue;
		if (!path.empty() && path[path.size() - 1] == dducks[now][i])continue;
		if (visited[now][dducks[now][i]] == 1)continue;
		visited[now][dducks[now][i]] = 1;
		path.push_back(dducks[now][i]);
		dfs(now + 1);
		path.pop_back();
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int dduck;
			cin >> dduck;
			dducks[i].push_back(dduck);
		}
		int cnt = 0;
		if (i != 0) {
			if (dducks[i - 1].size() == 1 && dducks[i].size() == 1 && dducks[i][0] == dducks[i - 1][0])cnt = 1;
		}
		if (cnt == 1) {
			flag = 1;
			break;
		}
	}
	if (flag == 1)cout << -1;
	if (flag == 0)dfs(0);
	if (flag == 0)cout << -1;
}