#include <iostream>
using namespace std;

int sudoku[9][9];
int result[9][9];
int yline[9][10];
int xline[9][10];
int square[9][10];
int num;

int check() {
	for (int i = 0; i < 9; i++) {
		int dat[10] = { 0 };
		int dat2[10] = { 0 };
		for (int j = 0; j < 9; j++) {
			if (dat[sudoku[i][j]] == 1)return 1;
			if (dat2[sudoku[i][j]] == 1)return 1;
			dat[sudoku[i][j]] = 1;
			dat2[sudoku[i][j]] = 1;
		}
	}
	int k = 0;
	int kk = 0;
	for (int h = 0; h < 3; h++) {
		kk = 0;
		int dat[10] = { 0 };
		for (int i = k; i < k + 3; i++) {
			for (int j = kk; j < kk + 3; j++) {
				if (dat[sudoku[i][j]] == 1)return 1;
				dat[sudoku[i][j]] = 1;
			}
			kk += 3;
		}
		k += 3;
	}
	return 0;
}

void play(int y, int x, int cnt) {
	if (y==9 && x==0) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					result[i][j] = sudoku[i][j];
				}
			}
		return;
	}
	if (sudoku[y][x] == 0) {
		for (int i = 1; i < 10; i++) {
			if (yline[y][i] == false && xline[x][i] == false && square[(y / 3) + (x / 3) * 3][i] == false) {
				yline[y][i] = true;
				xline[x][i] = true;
				square[(y / 3) + (x / 3) * 3][i] = true;
				sudoku[y][x] = i;
				if (x + 1 == 9)play(y + 1, 0, cnt);
				else play(y, x + 1, cnt);
				sudoku[y][x] = 0;
				yline[y][i] = false;
				xline[x][i] = false;
				square[(y / 3) + (x / 3) * 3][i] = false;
			}

		}
	}
	else {
		if (x + 1 == 9)play(y + 1, 0, cnt);
		else play(y, x + 1, cnt);
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] != 0)
			{
				yline[i][sudoku[i][j]] = true;
				xline[j][sudoku[i][j]] = true;
				square[(i / 3) + (j / 3)*3][sudoku[i][j]] = true;
			}
		}
	}
	play(0, 0, 0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}