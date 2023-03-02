#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 
* backward - 현재를 for로 back을 현재로 + 삭제
* forward - 현재를 back 로 저장 for를 현재로 + 삭제
access - for 전체 삭제 현재를 back으로 접속이 현재/ 캐시 넘치면 오래된 back 제거
compress - 뒤로 가기 공간 같은 번호 연속 최근 남기고 삭제/ 캐시 줄어듬
*/

long long n, q, c;
vector<long long>memory;
long long nowpage;
long long storage;
long long foresstorage;
long long backstorage;
deque<long long>fore;
deque<long long>back;

int main() {
	cin >> n >> q >> c;
	for (int j = 0; j < n; j++) {
		long long memorys;
		cin >> memorys;
		memory.push_back(memorys);
	}
	for (int i = 0; i < q; i++) {
		char cmd;
		cin >> cmd;
		if (cmd == 'A') {
			long long page;
			cin >> page;
			while (!fore.empty()) {
				fore.pop_back();
			}
			storage -= foresstorage;
			foresstorage = 0;
			if (nowpage != 0) {
				back.push_back(nowpage);
				backstorage += memory[nowpage - 1];
			}
			while (!back.empty() && storage + memory[page-1] > c ) {
				storage -= memory[back.front()-1];
				backstorage -= memory[back.front() - 1];
				back.pop_front();
			}
			nowpage = page;
			storage += memory[page-1];
		}
		else if (cmd == 'B') {
			if (back.size() == 0)continue;
			else {
				fore.push_back(nowpage);
				foresstorage += memory[nowpage - 1];
				nowpage = back.back();
				backstorage -= memory[back.back() - 1];
				back.pop_back();
			}
		}
		else if (cmd == 'C') {
			int k = 0;
			deque<long long>temp;
			while (!back.empty()) {
				if (k == back.back()) {
					back.pop_back();
					backstorage -= memory[k - 1];
					storage -= memory[k - 1];
				}
				else {
					k = back.back();
					back.pop_back();
					temp.push_back(k);
				}
			}
			while (!temp.empty()) {
				back.push_back(temp.back());
				temp.pop_back();
			}
		}
		else if (cmd == 'F') {
			if (fore.size() == 0)continue;
			else {
				back.push_back(nowpage);
				backstorage += memory[nowpage - 1];
				nowpage = fore.back();
				foresstorage -= memory[fore.back() - 1];
				fore.pop_back();
			}
		}
	}
	cout << nowpage << "\n";
	if (back.size() == 0)cout << -1;
	else {
		while (!back.empty()) {
			cout << back.back();
			if (back.size() != 1)cout << " ";
			back.pop_back();
		}
	}
	cout << "\n";
	if (fore.size() == 0)cout << -1;
	else {
		while (!fore.empty()) {
			cout << fore.back()<<" ";
			fore.pop_back();
		}
	}
}