#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;
	// now : 갯수
	// first : 몇 자리수 인지
	// second : 몇 개 인지
	// nown : 현재의 숫자
	int now = 0;
	int first = 1;
	int second = 1;
	int nown = 1;
	while (1) {
		now += first * second * 9;
		first++;
		nown += second * 9;
		second *= 10;
		if (nown > n) {
			first--;
			second /= 10;
			// 이전 수로 되돌리기
			nown -= second * 9;
			nown--;
			// 이전 갯 수로 되돌리기
			now -= first * second * 9;
			// 가능한 수
			int possible = n - nown;
			// if 가능한 수 * 자릿수 < k => -1
			if (now + possible * first < k)cout << -1;
			// 만일 더 작다면
			else {
				int calc = k - now;
				int final = 0;
				while (calc % first != 0) {
					calc--;
					final++;
				}
				nown += calc / first;
				if(final !=0)nown++;
				string str = to_string(nown);
				if (final == 0)cout << str[str.size()-1] << "\n";
				else cout << str[final-1]<<"\n";
			}
			break;
		}
		if (k < now) {
			first--;
			second /= 10;
			// 이전 수로 되돌리기
			nown -= second * 9;
			nown--;
			// 이전 갯 수로 되돌리기
			now -= first * second * 9;
			int calc = k - now;
			int final = 0;
			while (calc % first != 0) {
				calc--;
				final++;
			}
			nown += calc / first;
			if (final != 0)nown++;
			string str = to_string(nown);
			if (final == 0)cout << str[str.size() - 1] << "\n";
			else cout << str[final - 1] << "\n";
			break;
		}
	}
}