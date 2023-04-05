#include<iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, gun_m, gun_kill, bomb;
struct node {
	int m, kill;
};
queue<int>bombs;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> gun_m >> gun_kill >> bomb;
	int j = 0;
	int flag = 0;
	queue<node>q;
	for (int i = j; i < min(j + gun_m, n); i++) {
		int num;
		cin >> num;
		q.push({ i+1, num });
	}
	j = min(gun_m,n);
	while (!q.empty()) {
		flag = 0;
		int get_zero = 0;
		node now = q.front();
		q.pop();
		if (now.kill != 0) {
				while (!bombs.empty() && bombs.front() + gun_m -1< now.m) {
					bombs.pop();
				}
				now.kill -= (min(now.m, gun_m) - bombs.size()) * gun_kill;
				if (now.kill > 0) {
					if (bomb == 0)flag = 2;
					else {
						bomb--;
						bombs.push(now.m);
					}
				}
		}
		if (flag == 2) {
			cout << "NO";
			break;
		}
		j++;
		if (j <= n) {
			int num;
			cin >> num;
			q.push({ j, num });
		}
	}
	if (flag == 0)cout << "YES";
}