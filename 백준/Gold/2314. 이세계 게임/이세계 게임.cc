#include <iostream>
#include <vector>
using namespace std;

char now[4][4];
char future[4][4];
int answer=2134567890;
struct node {
	int y, x, flag;
};
vector<node>ltop;
vector<node>ptol;
int final[16][16];
int visited[16];
vector<int>path;

void dfs(int now) {
	if (path.size() == ltop.size()) {
		int temp = 0;
		for (int i = 0; i < path.size(); i++) {
			temp += final[i][path[i]];
		}
		if (temp < answer)answer = temp;
		return;
	}
	for (int i = 0; i < ltop.size(); i++) {
		if (visited[i] == 1)continue;
		visited[i] = 1;
		path.push_back(i);
		dfs(i);
		visited[i] = 0;
		path.pop_back();
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 4; j++) {
			now[i][j] = str[j];
		}
	}
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 4; j++) {
			future[i][j] = str[j];
			if (future[i][j] != now[i][j]) {
				if (now[i][j] == 'L')ltop.push_back({ i, j , 0});
				else ptol.push_back({ i, j , 0});
			}
		}
	}
	for (int i = 0; i < ltop.size(); i++) {
		int temp = 2134567890;
		int num = 0;
		for (int j = 0; j < ptol.size(); j++) {
			final[i][j] = abs(ltop[i].y - ptol[j].y) + abs(ltop[i].x - ptol[j].x);
		}
	}
	dfs(0);
	cout << answer;
}
