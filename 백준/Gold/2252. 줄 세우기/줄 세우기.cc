#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
// 앞사람이 다 나갔는지 확인
int flag[33000];
// 누가 내 뒤에 있는지 확인
vector<int>line[33000];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int f, b;
		cin >> f >> b;
		line[f].push_back(b);
		flag[b]++;
	}
	// bfs위한 큐
	queue<int>q;
	// 결과를 담는 큐
	queue<int>final;
	// 앞사람이 없으면 앞에 서도 된다 
	for (int i = 0; i < n; i++) {
		if (flag[i + 1] == 0) {
			q.push(i + 1);
			final.push(i + 1);
		}
	}
	// 만약 앞사람이 한명 남으면 남은 앞 한명은 now로 바로 줄세워도 된다 
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < line[now].size(); i++) {
			if (flag[line[now][i]] == 1) {
				q.push(line[now][i]);
				final.push(line[now][i]);
			}
			else flag[line[now][i]]--;
		}
	}
	while (!final.empty()) {
		cout << final.front()<<" ";
		final.pop();
	}
}
