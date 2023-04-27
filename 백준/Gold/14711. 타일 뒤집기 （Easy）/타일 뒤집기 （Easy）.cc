#include <iostream>
using namespace std;

int n;
// black = 1, white = 0
// 블랙이면 홀수번 뒤집히고
// 화이트면 짝수번 뒤집히고 
int tile[1001][1001];
int tmptile[1001][1001];
int checked[1001][1001];
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };

void turn(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + ydir[i];
		int nx = x + xdir[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		checked[ny][nx] ++;
	}
}

int main() {
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.')tile[0][i] = 0;
		else tile[0][i] = 1;
		tmptile[0][i] = tile[0][i];
	}
	for (int i = 0; i < str.size(); i++) {
		if (tile[0][i] == 1) {
			checked[0][i]++;
			turn(0, i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (checked[0][i] % 2 == 1) {
			if (tile[0][i] == 1)tmptile[0][i] = 0;
			else tmptile[0][i] = 1;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmptile[i - 1][j] == 1) {
				tile[i][j] = 1;
				tmptile[i][j] = 1;
				checked[i][j]++;
				turn(i, j);
			}
		}
		for (int j = 0; j < n; j++) {
			if (checked[i][j] % 2 == 1) {
				if (tmptile[i][j] == 1)tmptile[i][j] = 0;
				else tmptile[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tile[i][j] == 1)cout << "#";
			else cout << ".";
		}
		cout << "\n";
	}
}