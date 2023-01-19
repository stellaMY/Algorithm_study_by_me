#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
vector<int>v;
int final=2134567890;

void make(int nn, int cnt) {
	if (cnt == nn || cnt == nn-1||cnt == nn+1) {
		int now = 0;
		for (int i = 0; i < v.size(); i++) {
			now += v[i] * pow(10, v.size() - 1 - i);
		}
		if (cnt == 0)now = 2134567890;
		if (abs(now - n)+cnt < final)final = abs(now - n)+cnt;
		if(cnt == nn+1)return;
	}
	for (int i = 0; i < 10; i++) {
		if (arr[i] == 1)continue;
		if (cnt == 0 && i == 0 && nn>2)continue;
		v.push_back(i);
		make(nn, cnt + 1);
		v.pop_back();
	}
}

int main() {
	int now = 100;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		arr[num] = 1;
	}
	string num = to_string(n);
	final = min(final, abs(now - n));
	for (int i = 0; i < 1000000; i++) {
		string k = to_string(i);
		int flag = 0;
		for (int j = 0; j < k.size(); j++) {
			if (arr[k[j] - '0'] == 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			int kk = abs(n - i)+k.size();
			final = min(kk, final);
		}
	}
	cout << final;
}