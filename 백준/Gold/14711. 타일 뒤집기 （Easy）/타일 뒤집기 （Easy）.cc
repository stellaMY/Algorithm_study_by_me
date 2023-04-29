#include <iostream>
using namespace std;

int n;
// black = 1, white = 0
// 블랙이면 홀수번 뒤집히고
// 화이트면 짝수번 뒤집히고 
// 실제 타일
int tile[1001][1001];
// 변하는 과정의 타일
int tmptile[1001][1001];
// 총 몇번을 뒤집었는지
int checked[1001][1001];
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };

// 상하좌우로 회전 횟수 증가
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
	//1번째 행부터 n-1번째 행까지
	// 왼쪽에서 오른쪽으로 위의 타일을 확인하면서 타일 놓기
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 위의 타일이 현재 검정이면 아래에서 뒤집에 주어야 한다
			if (tmptile[i - 1][j] == 1) {
				tile[i][j] = 1;
				tmptile[i][j] = 1;
				checked[i][j]++;
				turn(i, j);
			}
		}
		for (int j = 0; j < n; j++) {
			// 두번 이상 뒤집으면 타일의 색이 바뀜
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
