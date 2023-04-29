#include <iostream>
#include <vector>
#include<algorithm>
#include <map>
using namespace std;

int n;
vector<string>str;
vector<string>answer;
int frontal[26];
int backal[26];
bool cmp(string a, string b) {
	if (a.size() > b.size())return true;
	if (a.size() < b.size())return false;
	return false;
}
int al[26];
map<string, int>check;

int main() {
	cin >> n;
	for (int i = 0; i < (n - 1) * 2; i++) {
		string strs;
		cin >> strs;
		str.push_back(strs);
		answer.push_back(strs);
		for (int j = 0; j < strs.size(); j++) {
			al[strs[j] - 'a']++;
		}
	}
	sort(str.begin(), str.end(), cmp);
	string one = str[0];
	string two = str[1];
	string three = str[str.size() - 1];
	string four = str[str.size() - 2];
	int flag = 0;
	int pcnt = 0;
	int scnt = 0;
	string real;
	string final;
	if (one + three == four + two) {
		final = one + three;
		for (int i = 0; i < (n - 1) * 2; i++) {
			int flag2 = 0;
			if (check[answer[i]] != 1&&final.substr(0, answer[i].size()) == answer[i]) {
				pcnt++;
				real += 'P';
				check[answer[i]] = 1;
				flag2 = 1;
			}
			if (flag2 == 0) {
				if (final.substr(final.size() - answer[i].size()) == answer[i]) {
					scnt++;
					real += 'S';
					flag2 = 1;
				}
			}
			if (flag2 == 0)break;
			if (i == (n - 1) * 2 - 1)flag = 1;
		}
	}
	if (flag == 0) {
		if (one + four == three + two) {
			final = one + four;
			real.clear();
			check.clear();
			for (int i = 0; i < (n - 1) * 2; i++) {
				int flag2 = 0;
				if (check[answer[i]] != 1 && final.substr(0, answer[i].size()) == answer[i]) {
					pcnt++;
					real += 'P';
					check[answer[i]] = 1;
					flag2 = 1;
				}
				if (flag2 == 0) {
					if (final.substr(final.size() - answer[i].size()) == answer[i]) {
						scnt++;
						real += 'S';
						flag2 = 1;
					}
				}
				if (flag2 == 0)break;
				if (i == (n - 1) * 2 - 1)flag = 1;
			}
		}
	}
	if (flag == 0){ 
		if (three + one == two + four) {
			final = three + one;
			real.clear();
			check.clear();
			for (int i = 0; i < (n - 1) * 2; i++) {
				int flag2 = 0;
				if (check[answer[i]] != 1 && final.substr(0, answer[i].size()) == answer[i]) {
					pcnt++;
					real += 'P';
					check[answer[i]] = 1;
					flag2 = 1;
				}
				if (flag2 == 0) {
					if (final.substr(final.size() - answer[i].size()) == answer[i]) {
						scnt++;
						real += 'S';
						flag2 = 1;
					}
				}
				if (flag2 == 0)break;
				if (i == (n - 1) * 2 - 1)flag = 1;
			}
		}
	}
	if (flag == 0) {
		if (four + one == two + three) {
			final = four + one;
			real.clear();
			check.clear();
			for (int i = 0; i < (n - 1) * 2; i++) {
				int flag2 = 0;
				if (check[answer[i]] != 1 && final.substr(0, answer[i].size()) == answer[i]) {
					pcnt++;
					real += 'P';
					check[answer[i]] = 1;
					flag2 = 1;
				}
				if (flag2 == 0) {
					if (final.substr(final.size() - answer[i].size()) == answer[i]) {
						scnt++;
						real += 'S';
						flag2 = 1;
					}
				}
				if (flag2 == 0)break;
				if (i == (n - 1) * 2 - 1)flag = 1;
			}
		}
	}
	cout << final << "\n" << real;
}