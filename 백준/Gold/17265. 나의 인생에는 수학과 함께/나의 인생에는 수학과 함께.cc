#include <iostream>
using namespace std;

int ydir[] = { 0,1 };
int xdir[] = { 1, 0 };
int n;
char map[6][6];
int high=-2134567890;
int low = 2134567890;
int visited[6][6];

int make(string str) {
	int num = str[0]-'0';
	for (int i = 2; i < str.size(); i++) {
		if (str[i] - '0' >= 0 && str[i] - '0'<=5) {
			if (str[i - 1] == '+') {
				num += str[i] - '0';
			}
			else if (str[i - 1] == '-') {
				num -= str[i] - '0';
			}
			else if (str[i - 1] == '*') {
				num *= str[i] - '0';
			}
		}
		else continue;
	}
	return num;
}

void dfs(int y, int x, string str) {
	if (y == n - 1 && x == n - 1) {
		int now = make(str);
		if (now < low)low = now;
		if (now > high)high = now;
		return;
	}
	for (int i = 0;i < 2; i++) {
		int ny = y + ydir[i];
		int nx = x + xdir[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (visited[ny][nx] != 0)continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, str + map[ny][nx]);
		visited[ny][nx] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	string str;
	str += map[0][0];
	visited[0][0] = 1;
	dfs(0, 0, str);
	cout << high << " "<<low;
}