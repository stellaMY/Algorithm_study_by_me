#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
struct node {
	int from, to, cost;
};
vector<node>house;
int parents[100001];
bool cmp(node a, node b) {
	if (a.cost < b.cost)return true;
	if (a.cost > b.cost)return false;
	return false;
}
long long answer;
vector<int>lastone;

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
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parents[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		house.push_back({ from, to, cost });
	}
	sort(house.begin(), house.end(), cmp);
	for (int i = 0; i < m; i++) {
		if (Find(house[i].from) == Find(house[i].to))continue;
		Union(house[i].from, house[i].to);
		answer += house[i].cost;
		lastone.push_back(house[i].cost);
	}
	cout << answer-lastone[lastone.size()-1];
}