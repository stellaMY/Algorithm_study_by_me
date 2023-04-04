#include <iostream>
using namespace std;

int n, m;
int tree[10][10];
int visited[10][10];
int result;
int final;
int boomerangs;
int ydir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int xdir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

void boomerang(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + ydir[i][0];
		int nx = x + xdir[i][0];
		int nny = y + ydir[i][1];
		int nnx = x + xdir[i][1];
		if (ny < 0 || nx < 0 || nny < 0 || nnx < 0 || ny >= n || nx >= m || nny >= n || nnx >= m)continue;
		if (visited[ny][nx] == 1 || visited[nny][nnx] == 1)continue;
		int k = x;
		visited[nny][nnx] = 1;
		visited[ny][nx] = 1;
		final += tree[ny][nx];
		final += tree[nny][nnx];
		if (result < final)result = final;
		for (int i = y; i < n; i++) {
			for (int j = k; j < m; j++) {
				if (visited[i][j] != 1) {
					final += tree[i][j] * 2;
					visited[i][j] = 1;
					boomerang(i, j);
					final -= tree[i][j] * 2;
					visited[i][j] = 0;
				}
			}
			k = 0;
		}
		visited[nny][nnx] = 0;
		visited[ny][nx] = 0;
		final -= tree[ny][nx];
		final -= tree[nny][nnx];
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tree[i][j];
		}
	}
	if (n <= 1 || m <= 1)cout << 0;
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				final = tree[i][j] * 2;
				visited[i][j] = 1;
				boomerang(i, j);
				visited[i][j] = 0;
			}
		}
		cout << result;
	}
}