#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long n, r, q;
vector<int>root[1000001];
int visited[100001] = { 0 };
int check[100001];
int result;
struct node {
	int num, stage;
};

void downs(int now) {
	for (int i = 0; i < root[now].size(); i++) {
		if (visited[root[now][i]] == 1)continue;
		visited[root[now][i]]= 1;
		check[now]++;
		downs(root[now][i]);
		check[now] += check[root[now][i]];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		int one, two;
		cin >> one >> two;
		root[one].push_back(two);
		root[two].push_back(one);
	}
	visited[r] = 1;
	downs(r);
	for (int i = 0; i < q; i++) {
		int roots;
		cin >> roots;
		if (check[roots] == 0)cout << 1 << "\n";
		else cout << check[roots]+1<<"\n";
	}
}