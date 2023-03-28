#include <iostream>
using namespace std;

//무조건 3씩 줘야한다 
//무조건 1과 2를 줘야해 
//한번에 줄어드는 건 3이야 
//2랑 1을 주는 횟수가 같아야해 
//전체 키/3은 3번 물 주는 횟수

long long final;
int n;
int real_one_cnt;
int one_cnt;
int two_cnt;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tree;
		cin >> tree;
		if (tree == 1) {
			real_one_cnt++;
			one_cnt++;
		}
		else {
			final += tree;
			while ( tree > 1) {
				tree -= 2;
				two_cnt++;
			}
			if (tree == 1)one_cnt++;
		}
	}
	if (one_cnt > two_cnt)cout << "NO";
	else if (one_cnt == two_cnt) {
		final -= real_one_cnt * 2;
		if (final % 3 == 0)cout << "YES";
		else cout << "NO";
	}
	else {
		final -= real_one_cnt * 2;
		if (final % 3 == 0)cout << "YES";
		else cout << "NO";
	}
}