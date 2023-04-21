#include <iostream>
using namespace std;

int nn;
int blue[4][6];
int green[6][4];
int score;

void gravity(int type) {
	if (type == 1) {
		for (int i = 5; i >=1; i--) {
			for (int j = 0; j < 4; j++) {
				if (green[i][j] == 0) {
					if (green[i - 1][j] == 0)continue;
					if (j!=3&&green[i - 1][j] == green[i - 1][j + 1]) {
						if (green[i][j + 1] != 0)continue;
						else {
							green[i][j] = green[i - 1][j];
							green[i][j + 1] = green[i - 1][j + 1];
							green[i - 1][j] = 0;
							green[i - 1][j + 1] = 0;
						}
					}
					else if (j != 0 && green[i - 1][j] == green[i - 1][j - 1]) {
						if (green[i][j - 1] != 0)continue;
						else {
							green[i][j] = green[i - 1][j];
							green[i][j - 1] = green[i - 1][j - 1];
							green[i - 1][j] = 0;
							green[i - 1][j - 1] = 0;
						}
					}
					else {
						green[i][j] = green[i - 1][j];
						green[i - 1][j] = 0;
					}
				}
			}
		}
		for (int j = 0; j < 4; j++) {
			if (green[5][j] == 0) {
				if (green[4][j] == 0)continue;
				if (j != 3 && green[4][j] == green[4][j + 1]) {
					if (green[5][j + 1] != 0)continue;
				}
				if (j != 0 && green[4][j] == green[4][j - 1]) {
					if (green[5][j - 1] != 0)continue;
				}
				gravity(1);
			}
		}
	}
	else {
		for (int i = 5; i >= 1; i--) {
			for (int j = 0; j < 4; j++) {
				if (blue[j][i] == 0) {
					if (blue[j][i - 1] == 0)continue;
					if (j!=3&&blue[j][i - 1] == blue[j + 1][i - 1]) {
						if (blue[j + 1][i] != 0)continue;
						else {
							blue[j][i] = blue[j][i - 1];
							blue[j + 1][i] = blue[j + 1][i - 1];
							blue[j][i - 1] = 0;
							blue[j + 1][i - 1] = 0;
						}
					}
					else if (j != 0 && blue[j][i - 1] == blue[j - 1][i - 1]) {
						if (blue[j - 1][i] != 0)continue;
						else {
							blue[j][i] = blue[j][i - 1];
							blue[j - 1][i] = blue[j - 1][i - 1];
							blue[j][i - 1] = 0;
							blue[j - 1][i - 1] = 0;
						}
					}
					else {
						blue[j][i] = blue[j][i - 1];
						blue[j][i - 1] = 0;
					}
				}
			}
		}
		for (int j = 0; j < 4; j++) {
			if (blue[j][5] == 0) {
				if (blue[j][4] == 0)continue;
				if (j != 3 && blue[j][4] == blue[j+1][4]) {
					if (blue[j+1][5] != 0)continue;
				}
				if (j != 0 && blue[j][4] == blue[j - 1][4]) {
					if (blue[j - 1][5] != 0)continue;
				}
				gravity(2);
			}
		}
	}
}

void nextcheck(int type) {
	int down = 0;
	if (type == 1) {
		int cnt = 0;
		for (int i = 0; i < 2; i++) {
			int num = 0;
			for (int j = 0; j < 4; j++) {
				if (blue[j][i] != 0)num=1;
			}
			cnt += num;
		}
		if (cnt == 1) {
			for (int i = 0; i < 4; i++) {
				blue[i][5] = 0;
			}
			gravity(2);
		}
		else if (cnt == 2) {
			for (int i = 4; i < 6; i++) {
				for (int j = 0; j < 4; j++) {
					blue[j][i] = 0;
				}
			}
			gravity(2);
		}
	}
	else {
		int cnt = 0;
		for (int i = 0; i < 2; i++) {
			int num = 0;
			for (int j = 0; j < 4; j++) {
				if (green[i][j] != 0)num = 1;
			}
			cnt += num;
		}
		if (cnt == 1) {
			for (int i = 0; i < 4; i++) {
				green[5][i] = 0;
			}
			gravity(1);
		}
		else if (cnt == 2) {
			for (int i = 4; i < 6; i++) {
				for (int j = 0; j < 4; j++) {
					green[i][j] = 0;
				}
			}
			gravity(1);
		}
	}
}

void check(int type) {
	int down = 0;
	if(type == 1){
		for (int i = 2; i < 6; i++) {
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (blue[j][i] !=0)cnt++;
			}
			if (cnt == 4) {
				score++;
				for (int j = 0; j < 4; j++) {
					blue[j][i] = 0;
				}
				down = 1;
			}
		}
		if (down == 1) {
			gravity(2);
			gravity(2);
			check(1);
		}
	}
	else {
		for (int i = 2; i < 6; i++) {
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (green[i][j] != 0)cnt++;
			}
			if (cnt == 4) {
				score++;
				for (int j = 0; j < 4; j++) {
					green[i][j] = 0;
				}
				down = 1;
			}
		}
		if (down == 1) {
			gravity(1);
			gravity(1);
			check(2);
		}
	}
}

int main() {
	cin >> nn;
	int flag = 0;
	for (int n = 1; n <= nn; n++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			flag = 0;
			for (int i = 0; i < 6; i++) {
				if (blue[y][i] != 0) {
					blue[y][i-1] = n;
					flag = 1;
					break;
				}
			}
			if (flag == 0)blue[y][5] = n;
			flag = 0;
			for (int i = 0; i < 6; i++) {
				if (green[i][x] != 0) {
					green[i-1][x] = n;
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				green[5][x] = n;
			}
			check(1);
			check(2);
			nextcheck(1);
			nextcheck(2);
		}
		else if (t == 2) {
			int temp=9;
			flag = 0;
			for (int i = 0; i < 6; i++) {
				if (blue[y][i] != 0) {
					temp = i - 1;
					flag = 1;
					break;
				}
			}
			for (int i = 0; i < 6; i++) {
				if (blue[y+1][i] != 0) {
					if(temp>i-1)temp = i - 1;
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				blue[y][5] = n;
				blue[y+1][5] =n;
			}
			else if (flag == 1) {
				blue[y][temp] = n;
				blue[y + 1][temp] = n;
			}
			flag = 0;
			for (int i = 0; i < 6; i++) {
				if (green[i][x] != 0) {
					green[i - 1][x] = n;
					green[i - 2][x] = n;
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				green[5][x] = n;
				green[4][x] = n;
			}
			check(1);
			check(2);
			nextcheck(1);
			nextcheck(2);
		}
		else if (t == 3) {
			flag = 0;
			for (int i = 0; i < 6; i++) {
				if (blue[y][i] != 0) {
					blue[y][i - 1] = n;
					blue[y][i - 2] = n;
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				blue[y][5] = n;
				blue[y][4] = n;
			}
			int temp = 9;
			flag = 0;
			for (int i = 0; i < 6; i++) {
				if (green[i][x] != 0) {
					temp = i - 1;
					flag = 1;
					break;
				}
			}
			for (int i = 0; i < 6; i++) {
				if (green[i][x+1] != 0) {
					if (temp > i - 1)temp = i - 1;
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				green[5][x] = n;
				green[5][x + 1] = n;
			}
			if (flag == 1) {
				green[temp][x] = n;
				green[temp][x + 1] = n;
			}
			check(1);
			check(2);
			nextcheck(1);
			nextcheck(2);
		}
	}

	cout << score << "\n";

	int final = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (blue[i][j] != 0)final++;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (green[j][i] != 0)final++;
		}
	}
	cout << final;
}