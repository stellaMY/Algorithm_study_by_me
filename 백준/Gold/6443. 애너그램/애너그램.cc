#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int cnt[21];
int n;
int al[30][21];
int alpha[30];
string str;
vector<string>v;
unordered_map<string, int>checked;
vector<int>path;

void dfs(int now, string tmp) {
	if (now == n) {
		if (checked[tmp] == 1)return;
		cout << tmp << "\n";
		checked[tmp] = 1;
		return;
	}
	for (int i = 0; i <= 26; i++) {
		if (alpha[i] == 0)continue;
		if (alpha[i] == 2 && al[i][now] == 1)continue;
		if (alpha[i] == 2) {
			al[i][now] = 1;
		}
		alpha[i]--;
		tmp.push_back(i + 'a');
		dfs(now + 1, tmp);
		alpha[i]++;
		if (alpha[i] == 2) {
			al[i][now] = 0;
		}
		tmp.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> str;
		v.clear();
		checked.clear();
		for (int i = 0; i < 27; i++) {
			alpha[i] = 0;
		}
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 21; j++) {
				al[i][j] = 0;
			}
		}
		for (int i = 0; i < str.size(); i++) {
			alpha[str[i]-'a']++;
		}
		n = str.size();
		string tmp;
		dfs(0, tmp);
	}
}