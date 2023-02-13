#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int arr[15][15];
int ydir[] = { 0,1 };
int xdir[] = { 1,0 };
struct node {
	int y, x, nows;
};

int bfs(int sy, int sx, int fy, int fx) {
	int visited[15][15] = { 0 };
	visited[sy][sx] = 1;
	int final = 0;
	queue<node>q;
	q.push({ sy, sx });
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny > fy || nx > fx)continue;
			if (ny == fy && nx == fx) {
				final++;
				continue;
			}
			q.push({ ny, nx });
		}
	}
	return final;
}

int main() {
	cin >> n >> m >> k;
	if (k == 0) {
		int first = bfs(0, 0, n - 1, m - 1);
		cout << first;
	}
	else {
		int y = k / m;
		int x = k % m;
		if (k % m != 0)y++;
		y--;
		x--;
		int first = bfs(0,0,y, x);
		int second = bfs(y, x, n - 1, m - 1);
		cout << first * second;
	}
}