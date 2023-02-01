#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int y, x, cnt;
};
int n, m;
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };
int sea[21][21];
int sharky, sharkx, sharksize;
vector<node>fish[7];
int num = 1;
int flag = 0;
int final = 0;
int fakesharksize = 0;

int check(int y, int x) {
	int visited[21][21] = { 0 };
	queue<node>q;
	q.push({ sharky, sharkx, 0 });
	visited[sharky][sharkx] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.y == y && now.x == x) return now.cnt;
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
			if (sea[ny][nx] > sharksize)continue;
			if (visited[ny][nx] == 1)continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx, now.cnt+1 });
			if (ny == y && nx == x)return now.cnt + 1;
		}
	}
	return 2134567891;
}

void eat() {
	int minval = 2134567890;
	int now = 0;
	int y = 0;
	int k = sharksize;
	if (k >= 7)k = 7;
	for (int j = 1; j < k; j++) {
		for (int i = 0; i < fish[j].size(); i++) {
			if (sea[fish[j][i].y][fish[j][i].x] == 0)continue;
			if (check(fish[j][i].y, fish[j][i].x) < minval) {
				minval = check(fish[j][i].y, fish[j][i].x);
				now = i;
				flag = 1;
				y = j;
			}
			if (check(fish[j][i].y, fish[j][i].x) == minval) {
				if (fish[y][now].y < fish[j][i].y)continue;
				else if (fish[y][now].y == fish[j][i].y) {
					if (fish[y][now].x > fish[j][i].x) {
						now = i;
						y = j;
					}
				}
				else {
					now = i;
					y = j;
				}
			}
		}
	}
	if (flag == 1) {
		final += minval;
		fakesharksize++;
		if (fakesharksize >= sharksize) {
			fakesharksize -= sharksize;
			sharksize++;
		}
		sharky = fish[y][now].y;
		sharkx = fish[y][now].x;
		sea[sharky][sharkx] = 0;
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sea[i][j];
			if (sea[i][j] == 9) {
				sharky = i;
				sharkx = j;
				sea[i][j] = 0;
			}
			else if (sea[i][j] != 0)fish[sea[i][j]].push_back({ i, j });
		}
	}
	sharksize = 2;
	while (1) {
		flag = 0;
		eat();
		if (flag == 0)break;
	}
	cout << final;
}