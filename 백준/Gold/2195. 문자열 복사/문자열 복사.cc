#include <iostream>
using namespace std;

int main() {
	string s, p;
	cin >> s >> p;
	string test;
	int answer = 0;
	while (test!=p) {
		int num = 0;
		int cnt = 0;
		int savenum = 0;
		int savecnt = 0;
		for (int i = 0; i<s.size(); i++) {
			if (s[i] == p[test.size()]) {
				num = i+1;
				cnt = 1;
				while (num<s.size()&&test.size()+cnt<p.size()&&s[num] == p[test.size() + cnt]) {
					num++;
					cnt++;
				}
				if (savecnt < cnt) {
					savenum = i;
					savecnt = cnt;
				}
			}
		}
		for (int j = 0; j < savecnt; j++) {
			test += s[savenum + j];
		}
		answer++;
	}
	cout << answer;
}