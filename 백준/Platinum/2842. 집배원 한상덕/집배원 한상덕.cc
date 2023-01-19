#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;

struct node {
	int y, x;
};
struct Node {
	int maxi, mini;
};
vector<Node>godo[1000000];

char map[51][51];
int arr[51][51];
int n;
int cnt = 0;
int y, x;
int tired[3000];
int bfscnt = 0;
int xdir[] = { 0, 0, 1, 1, -1, -1, 1, -1 };
int ydir[] = { 1, -1, -1, 1, 1, -1, 0, 0 };
int leftt = 0;
int rightt = 0;
int visited[51][51];
vector<int>height;
vector<int>office;

void bfs(int left, int right) {
	bfscnt = 0;
	queue<node>q;
	q.push({ y, x });
	visited[y][x] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
			if (visited[ny][nx] == 1)continue;
			if (arr[ny][nx]<left || arr[ny][nx]>right)continue;
			visited[ny][nx] = 1;
			if (map[ny][nx] == 'K')bfscnt++;
			q.push({ ny, nx });
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'P') {
				y = i;
				x = j;
			}
			if (map[i][j] == 'K')cnt++;
		}
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			height.push_back(arr[i][j]);
			if (map[i][j] == 'K' || map[i][j] == 'P')office.push_back(arr[i][j]);
		}
	}
	sort(height.begin(), height.end());
	sort(office.begin(), office.end());
	int it = 0;
	for (int i = 0; i < height.size(); i++) {
		if (height[i] == office[0]) {
			it = i;
			break;
		}
	}
	int maxval = 2134567890;
	for (int i = 0; i <= it; i++) {
		int start = height[i];
		int left = office[office.size() - 1];
		int right = height[height.size() - 1];
		while (left <= right) {
			int middle = (left + right) / 2;
			memset(visited, 0, sizeof(visited));
			bfs(start, middle);
			if (bfscnt == cnt) {
				if(middle-start<maxval)maxval = middle - start;
				right = middle - 1;
			}
			else left = middle + 1;
		}
	}
	cout << maxval;
}