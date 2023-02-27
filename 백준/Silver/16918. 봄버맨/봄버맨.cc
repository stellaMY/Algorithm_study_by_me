#include <iostream>
using namespace std;

int bomb[201][201];
int r, c, n;
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };

void put() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (bomb[i][j] == 0)bomb[i][j] = 2;
			else if (bomb[i][j] == 1)bomb[i][j] = -1;
			else bomb[i][j]--;
		}
	}
}

void pangpang() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (bomb[i][j] == 0)continue;
			if (bomb[i][j] == -1) {
				bomb[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					int ny = i + ydir[k];
					int nx = j + xdir[k];
					if (ny < 0 || nx < 0 || ny >= r || nx >= c)continue;
					if (bomb[ny][nx] == -1)continue;
					bomb[ny][nx] = 0;
				}
			}
			else if (bomb[i][j] == 1)bomb[i][j] = -1;
			else bomb[i][j]--;
		}
	}
}

int main() {
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			if (str[j] == 'O')bomb[i][j] = 1;
			else bomb[i][j] = 0;
		}
	}
	for (int i = 1; i < n; i++) {
		if (i % 2 == 1)put();
		else pangpang();
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (bomb[i][j] == 0)cout << ".";
			else cout << "O";
		}
		cout << "\n";
	}
}