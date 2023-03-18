#include <iostream>
#include <queue>
using namespace std;

int w, h, ty, tx;
char ice[501][501];
long long visited[501][501];
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };
struct node {
	long long y, x, cnt;
};
bool operator <(node a, node b) {
	if (a.cnt > b.cnt)return true;
	if (a.cnt < b.cnt)return false;
	return false;
}
long long result = 2134567890;


void adventure(int ty, int tx) {
	priority_queue<node>q;
	q.push({ ty, tx, 0 });
	while (!q.empty()) {
		node now = q.top();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w)continue;
			if (ice[ny][nx] == 'R')continue;
			if (ice[ny][nx] == 'H')continue;
			if (ice[ny][nx] == 'E') {
				if (result > now.cnt)result = now.cnt;
				continue;
			}
			else if(ice[ny][nx]>=0&&ice[ny][nx]<10){
				long long num = now.cnt;
				long long nny = ny;
				long long nnx = nx;
				long long flag2 = 0;
				num += ice[ny][nx];
				while (1) {
					nny += ydir[i];
					nnx += xdir[i];
					if (nny < 0 || nnx < 0 || nny >= h || nnx >= w) {
						flag2 = 1;
						break;
					}
					if (ice[nny][nnx] == 'R')break;
					if (ice[nny][nnx] == 'H') {
						flag2 = 1;
						break;
					}
					if (ice[nny][nnx] == 'E') {
						if (result > num)result = num;
						flag2 = 1;
						break;
					}
					num += ice[nny][nnx];
				}
				if (flag2 == 1)continue;
				if (nny-ydir[i] == ty && nnx-xdir[i] == tx) continue;
				if (visited[nny - ydir[i]][nnx - xdir[i]] != 0 && visited[nny - ydir[i]][nnx - xdir[i]] <= num)continue;
				q.push({ nny - ydir[i], nnx - xdir[i], num });
				visited[nny - ydir[i]][nnx - xdir[i]] = num;
			}
		}
	}
}

int main() {
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < w; j++) {
			if (str[j] >= 'A' && str[j] <= 'Z')ice[i][j] = str[j];
			else ice[i][j] = str[j] - '0';
			if (str[j] == 'T') {
				ty = i; tx = j;
				ice[i][j] = 0;
			}
		}
	}
	adventure(ty, tx);
	if (result == 2134567890)cout << -1;
	else cout << result;
}

/*
5 5
2E115
32411
11313
R42TR
124R6



aaa...
bb....
....cc
..dd..
...aaa
*/