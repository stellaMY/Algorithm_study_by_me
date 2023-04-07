#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
char miro[51][51];
struct node {
	int y, x, get_key;
	int result;
};
//int get_key_cnt[6];
//int get_key;
int miny, minx;
int final = 2134567890;
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };
int visited[51][51][50];

void find_moon(int y, int x) {
	queue<node>q;
	q.push({ y,x,0 ,0});
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		int tmp = now.get_key;
		if (now.result >= final)continue;
		for (int i = 0; i < 4; i++) {
			now.get_key = tmp;
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (miro[ny][nx] == '#')continue;
			//if (visited[ny][nx][now.get_key] != 0 && visited[ny][nx][now.get_key] <= now.result)continue;
			if (miro[ny][nx] < 'g' && miro[ny][nx] >= 'a') {
				now.get_key = now.get_key | (1 << (miro[ny][nx] - 'a'));
			}
			if (miro[ny][nx] < 'G' && miro[ny][nx] >= 'A') {
				if ((now.get_key & (1 << miro[ny][nx] - 'A')) == 0)continue;
			}
			if (visited[ny][nx][now.get_key] !=0)continue;
			visited[ny][nx][now.get_key] = now.result + 1;
			if (miro[ny][nx] == '1') {
				if (final > now.result+1)final = now.result+1;
				continue;
			}
			q.push({ ny, nx, now.get_key, now.result+1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> miro[i][j];
			if (miro[i][j] == '0') {
				miny = i;
				minx = j;
				visited[i][j][0] = 1;
			}
		}
	}
	find_moon(miny, minx);
	if (final == 2134567890)cout << -1;
	else cout << final;
}