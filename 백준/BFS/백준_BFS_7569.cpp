#include <iostream>
#include <queue>
using namespace std;

int tomato[101][101][101];
int visited[101][101][101];
int n, m, h;
struct node {
	int y, x, h, cnt;
};
queue<node>q;
int none;
int ydir[] = { 0,0,1,-1 };
int xdir[] = { -1,1,0,0 };

void rotten() {
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (tomato[now.h][ny][nx] == 1)continue;
			if (tomato[now.h][ny][nx] == -1)continue;
			if (tomato[now.h][ny][nx] == 0) {
				visited[now.h][ny][nx] = now.cnt + 1;
				tomato[now.h][ny][nx] = 1;
			}
			q.push({ny, nx,now.h,  now.cnt + 1 });
		}
		for (int i = -1; i <= 1; i += 2) {
			int nh = now.h + i;
			if (nh < 0 || nh >= h)continue;
			if (tomato[nh][now.y][now.x] == 1)continue;
			if (tomato[nh][now.y][now.x] == -1)continue;
			if (tomato[nh][now.y][now.x] == 0) {
				visited[nh][now.y][now.x] = now.cnt + 1;
				tomato[nh][now.y][now.x] = 1;
			}
			q.push({ now.y, now.x, nh, now.cnt + 1 });
		}
	}
}

int main() {
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)q.push({ j, k,i, 0 });
				if (tomato[i][j][k] == -1)none++;
			}
		}
	}
	if (q.size() + none == h * n * m)cout << 0;
	else {
		rotten();
		int maxval = 0;
		int flag = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (tomato[i][j][k] == 0)flag = 1;
					if (visited[i][j][k]>maxval)maxval = visited[i][j][k];
				}
			}
		}
		if (flag == 1)cout << -1;
		else cout << maxval;
	}
}