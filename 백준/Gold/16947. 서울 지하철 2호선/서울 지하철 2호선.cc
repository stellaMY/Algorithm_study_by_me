#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int check[3001];
struct node {
	int now;
	vector<int>path;
};
vector<int>sub[3001];
int visited[3001];
int final[3001];
int flag;
vector<int>path;

void circle(int now, int start) {
	if (check[now] == 1)return;
	if (path.size()> 2 && now == start) {
		for (int i = 0; i < path.size(); i++) {
			final[path[i]] = 4000;
		}
		flag = 2;
		return;
	}
	for (int i = 0; i < sub[now].size(); i++) {
		if (visited[sub[now][i]] == 1)continue;
		visited[sub[now][i]] = 1;
		path.push_back(sub[now][i]);
		flag = 1;
		circle(sub[now][i], start);
		path.pop_back();
		visited[sub[now][i]] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		sub[from].push_back(to);
		sub[to].push_back(from);
		check[from]++;
		check[to]++;
	}
	queue<node>q;
	vector<int>path;
	int start = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] >= 2) {
			flag = 0;
			circle(i, i);
		}
		if (flag == 2)break;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 1) {
			int visited[3001] = { 0 };
			int now = i;
			queue<node>q;
			vector<int>path;
			path.push_back(now);
			q.push({ now, path });
			while (!q.empty()) {
				node n = q.front();
				q.pop();
				for (int i = 0; i < sub[n.now].size(); i++) {
					vector<int>temp;
					temp = n.path;
					if (final[sub[n.now][i]] == 4000) {
						for (int i = 0; i < n.path.size(); i++) {
							final[n.path[i]] = n.path.size() - i;
						}
						break;
					}
					if (check[sub[n.now][i]] == 1)continue;
					if (visited[sub[n.now][i]]==1)continue;
					temp.push_back(sub[n.now][i]);
					visited[sub[n.now][i]]=1;
					q.push({ sub[n.now][i], temp });
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (final[i] == 4000)cout << 0 << " ";
		else cout << final[i] << " ";
	}
}