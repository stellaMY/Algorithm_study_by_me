#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

string n;
int m;
int result;
int num[10] = { 0 };
struct node {
	string num;
	int cnt;
};
int visited[11][1000001];

int change_num(string str) {
	int num = 0;
	for (int i = 0; i < str.size(); i++) {
		num += pow( 10, str.size() - 1 - i) * (str[i] - '0');
	}
	return num;
}

void change(int num) {	
	queue<node>q;
	q.push({ n, 0 });
	while (!q.empty()) {
		int num[10] = { 0 };
		node now = q.front();
		q.pop();
		for (int i = 0; i < now.num.size(); i++) {
			num[i] = now.num[i] - '0';
		}
		for (int i = 0; i < now.num.size(); i++) {
			for (int j = i+1; j < now.num.size(); j++) {
				int tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
				string tmp_str;
				for (int i = 0; i < now.num.size(); i++) {
					tmp_str += num[i] + '0';
				}
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
				if (tmp_str[0] == '0')continue;
				int tmp_cnt = change_num(tmp_str);
				if (visited[now.cnt + 1][tmp_cnt] == 1)continue;
				visited[now.cnt + 1][tmp_cnt] = 1;
				if (now.cnt + 1 == m) {
					if (result < tmp_cnt)result = tmp_cnt;
				}
				else q.push({ tmp_str, now.cnt + 1 });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	if (n.size() == 1)cout << -1;
	else if (n.size() == 2 && n[1] == '0')cout << -1;
	else {
		change(0);
		cout << result;
	}
}