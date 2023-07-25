#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

long long build[1005];
long long check[1005];
long long flag[1005];
vector<long long>v[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long t;
	cin >> t;
	for (long long i = 0; i < t; i++) {
		long long n, k;
		cin >> n >> k;
		for (long long j = 0; j < n; j++) {
			cin >> build[j+1];
		}
		for (long long j = 0; j < k; j++) {
			long long from, to;
			cin >> from >> to;
			v[from].push_back(to);
			flag[to]++;
		}
		long long need;
		cin >> need;
		queue<long long>q;
		for (int i = 1; i <= n; i++) {
			if (flag[i] == 0) {
				q.push(i );
				check[i ]= build[i];
			}
		}
		while (!q.empty()) {
			long long now = q.front();
			q.pop();
			for (long long i = 0; i < v[now].size(); i++) {
				check[v[now][i]] = max(check[v[now][i]], check[now] + build[v[now][i]]);
				flag[v[now][i]]--;
				if(flag[v[now][i]]==0)q.push(v[now][i]);
			}
		}
		cout << check[need] << "\n";
		for (long long i = 0; i < 1000; i++) {
			build[i] = 0;
			check[i] = 0;
			flag[i] = 0;
			v[i].clear();
		}
	}
}
