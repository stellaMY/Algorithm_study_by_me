#include <iostream>
#include <vector>
using namespace std;

int n, m;
int semester;
vector<int>v[1001];
int visited[1001];
int check[1001];

void downs(int now) {
	if (v[now].size() == 0)check[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		//if (visited[v[now][i]] == 1)continue;
		if (check[v[now][i]] != 0) {
			if(check[now]<check[v[now][i]]+1)check[now] = check[v[now][i]] + 1;
			continue;
		}
		//visited[v[now][i]] = 1;
		downs(v[now][i]);
		if(check[now]<check[v[now][i]+1]) check[now] = check[v[now][i]]+1;
	}
}

void down(int now) {
	for (int i = 0; i < v[now].size(); i++) {
		semester++;
		down(v[now][i]);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		downs(i);
		cout << check[i] << " ";
	}
}