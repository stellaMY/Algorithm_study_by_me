#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int from, to, cost;
};
vector<node>tree;
int parents[10001];
bool cmp(node a, node b) {
	if (a.cost > b.cost)return false;
	if (a.cost < b.cost)return true;
	return false;
}

int Find(int now) {
	if (now == parents[now])return now;
	return parents[now] = Find(parents[now]);
}

void Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	parents[pB] = pA;
}

int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 0; i <= v; i++) {
		parents[i] = i;
	}
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		tree.push_back({ from, to, cost });
	}
	sort(tree.begin(), tree.end(), cmp);
	int sum = 0;
	for (int i = 0; i < e; i++) {
		int from = tree[i].from;
		int to = tree[i].to;
		if (Find(from) == Find(to))continue;
		Union(from, to);
		sum += tree[i].cost;
	}
	cout << sum;
}