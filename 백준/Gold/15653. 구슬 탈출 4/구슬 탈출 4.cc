#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int board[10][10];
int redy, redx, bluey, bluex;
// 빨간공이 몇번째에 어디에 있는지 저장
int redvisited[10][10][1000];
// 파란공이 몇번째에 어디에 있는지 저장
int bluevisited[10][10][1000];
struct node {
	int redy, redx, bluey, bluex, num;
};
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };
int answer =2134567890;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			board[i][j] = str[j];
			if (board[i][j] == 'B') {
				bluey = i; bluex = j;
				bluevisited[i][j][1] = 1;
			}
			else if (board[i][j] == 'R') {
				redy = i; redx = j;
				redvisited[i][j][1] = 1;
			}
		}
	}
	// 몇번째인지
	int k = 2;
	queue<node>marble;
	marble.push({ redy, redx, bluey, bluex, 0 });
	while (!marble.empty()) {
		node now = marble.front();
		marble.pop();
		// 빨간 탈출구 확인
		int redflag = 0;
		// 파란 탈출구 확인
		int blueflag = 0;
		int check = 0;
		// 수평으로 이동
		for (int i = 0; i < 2; i++) {
			redflag = 0;
			blueflag = 0;
			check = 0;
			int rny = now.redy; int rnx = now.redx; int bny = now.bluey; int bnx = now.bluex;
			while (1) {
				rnx += xdir[i];
				// 탈출구라면 확인
				if (board[rny][rnx] == 'O') {
					redflag = 1;
					break;
				}
				// 만약 파란 구슬과 같은 위치라면
				// 우선 파란 구슬을 이동시키고 빨간 구슬 이동
				if (rnx == bnx && bny == rny) {
					while (1) {
						bnx += xdir[i];
						if (board[bny][bnx] == '#') {
							bnx -= xdir[i];
							break;
						}
						if (board[bny][bnx] == 'O') {
							blueflag = 1;
							break;
						}
					}
					rnx = bnx - xdir[i];
					check = 1;
					break;
				}
				// 벽이라면 멈추기
				if (board[rny][rnx] == '#') {
					rnx -= xdir[i];
					break;
				}
			}
			// 빨간 구슬을 욺직일때 파란 구슬을 욺직이지 않았다면
			while (check==0) {
				bnx += xdir[i];
				if (board[bny][bnx] == 'O') {
					blueflag = 1;
					break;
				}
				// 만약 빨간 구슬과 위치가 같다면 멈추기
				if (bnx == rnx && rny == bny) {
					bnx -= xdir[i];
					break;
				}
				if (board[bny][bnx] == '#') {
					bnx -= xdir[i];
					break;
				}
			}
			int flag = 0;
			// 만약 앞선 순서에서 현재의 빨간 구슬과 파란 구슬이 같은 위치였다면 패스
			for (int i = 1; i < k; i++) {
				if (redvisited[rny][rnx][i] == 1 && bluevisited[bny][bnx][i] == 1) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)continue;
			if (blueflag == 1)continue;
			// 빨간 구슬만 들어간다면 정답 갱신
			if (redflag == 1) {
				if (answer > now.num + 1)answer = now.num + 1;
				continue;
			}
			redvisited[rny][rnx][k] = 1;
			bluevisited[bny][bnx][k] = 1;
			k++;
			marble.push({ rny, rnx, bny, bnx, now.num + 1 });
		}
		for (int i = 2; i < 4; i++) {
			redflag = 0;
			blueflag = 0;
			check = 0;
			int rny = now.redy; int rnx = now.redx; int bny = now.bluey; int bnx = now.bluex;
			while (1) {
				rny += ydir[i];
				if (board[rny][rnx] == 'O') {
					redflag = 1;
					break;
				}
				if (rny == bny && rnx==bnx) {
					while (1) {
						bny += ydir[i];
						if (board[bny][bnx] == '#') {
							bny -= ydir[i];
							break;
						}
						if (board[bny][bnx] == 'O') {
							blueflag = 1;
							break;
						}
					}
					rny = bny - ydir[i];
					check = 1;
					break;
				}
				if (board[rny][rnx] == '#') {
					rny -= ydir[i];
					break;
				}
			}
			while (check==0) {
				bny += ydir[i];
				if (board[bny][bnx] == 'O') {
					blueflag = 1;
					break;
				}
				if (bny == rny && rnx == bnx) {
					bny -= ydir[i];
					break;
				}
				if (board[bny][bnx] == '#') {
					bny -= ydir[i];
					break;
				}
			}
			int flag = 0;
			for (int i = 1; i < k; i++) {
				if (redvisited[rny][rnx][i] == 1 && bluevisited[bny][bnx][i] == 1) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)continue;
			if (blueflag == 1)continue;
			if (redflag == 1) {
				if (answer > now.num + 1)answer = now.num + 1;
				continue;
			}
			redvisited[rny][rnx][k] = 1;
			bluevisited[bny][bnx][k] = 1;
			k++;
			marble.push({ rny, rnx, bny, bnx, now.num + 1 });
		}
	}
	if (answer == 2134567890)cout << -1;
	else cout << answer;
}
