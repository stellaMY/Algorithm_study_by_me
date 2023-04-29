#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 나올 수 있는 원래의 문자열의 갯수는 4개 뿐이다.
// 하나씩 확인하면서 아니라면 다음 경우의 수로 넘어간다.
int n;
vector<string>answer;
// 접두사의 중복 체크
map<string, int>check;

int main() {
	cin >> n;
	// 후보가 될 수 있는 문장을 만들기 위한 가장 작은 접두사, 접미사와
	// 가장 큰 접두사, 접미사.
	string one, two, three, four;
	for (int i = 0; i < (n - 1) * 2; i++) {
		string strs;
		cin >> strs;
		answer.push_back(strs);
		if (strs.size() == 1 && three.size() == 0)three = strs;
		else if(strs.size() == 1 && three.size() != 0)four = strs;
		if (strs.size() == n - 1 && one.size() == 0)one = strs;
		else if (strs.size() == n - 1 && one.size() != 0) two = strs;
	}
	// 만든 문장이 맞는지 확인
	int flag = 0;
	// 답이 되는 접미사 접두사의 순서
	string real;
	// 답이 되는 문장
	string final;
	if (one + three == four + two) {
		final = one + three;
		for (int i = 0; i < (n - 1) * 2; i++) {
			int flag2 = 0;
			// check에서 이미 접두사로 확인한 문장이 나오면 접미사로 패스
			if (check[answer[i]] != 1&&final.substr(0, answer[i].size()) == answer[i]) {
				real += 'P';
				check[answer[i]] = 1;
				flag2 = 1;
			}
			if (flag2 == 0) {
				if (final.substr(final.size() - answer[i].size()) == answer[i]) {
					real += 'S';
					flag2 = 1;
				}
			}
			// 접두사도 접미사도 될 수 없는 문장이 있다면 다음 경우의 수로
			if (flag2 == 0)break;
			// 마지막까지 확인이 완료되면 이 경우의 수가 답
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
					real += 'P';
					check[answer[i]] = 1;
					flag2 = 1;
				}
				if (flag2 == 0) {
					if (final.substr(final.size() - answer[i].size()) == answer[i]) {
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
					real += 'P';
					check[answer[i]] = 1;
					flag2 = 1;
				}
				if (flag2 == 0) {
					if (final.substr(final.size() - answer[i].size()) == answer[i]) {
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
					real += 'P';
					check[answer[i]] = 1;
					flag2 = 1;
				}
				if (flag2 == 0) {
					if (final.substr(final.size() - answer[i].size()) == answer[i]) {
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