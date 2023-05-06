#include <iostream>
using namespace std;

int n, m, k;
struct node {
	int jungle, ocean, ice;
};
// 각각의 갯수가 몇개 들어있는지 저장
node map[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		// 앞의 갯수와 현재의 값을 확인하면서 저장
		// 이후에 현재의 값을 추가해주기
		for (int j = 1; j <= m; j++) {
			map[i][j].jungle = map[i][j - 1].jungle + map[i-1][j].jungle -map[i-1][j-1].jungle;
			map[i][j].ocean = map[i][j - 1].ocean + map[i - 1][j].ocean - map[i - 1][j-1 ].ocean;
			map[i][j].ice = map[i][j - 1].ice + map[i - 1][j].ice - map[i - 1][j-1 ].ice;
			if (str[j-1] == 'J') {
				map[i][j].jungle++;
			}
			else if (str[j-1] == 'I') {
				map[i][j].ice++;
			}
			else if (str[j-1] == 'O') {
				map[i][j].ocean++;
			}
		}
	}
	// k 개만큼 받고 계산
	// 큰 사각형의 크기에서 작은 크기 사각형과의 차이를 빼고 작은 사각형을 더하면 된다
	for (int i = 0; i < k; i++) {
		int y, x, yy, xx;
		cin >> y >> x >> yy >> xx;
		cout << map[yy][xx].jungle + map[y-1][x-1].jungle - map[y-1][xx].jungle - map[yy][x-1].jungle<<" ";
		cout << map[yy][xx].ocean + map[y-1][x-1].ocean - map[y - 1][xx].ocean - map[yy][x - 1].ocean << " ";
		cout << map[yy][xx].ice + map[y-1][x-1].ice - map[y - 1][xx].ice - map[yy][x - 1].ice << "\n";
	
	}
}
