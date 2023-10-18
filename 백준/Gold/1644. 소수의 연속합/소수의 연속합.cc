#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int>prime;
int arr[4000001];

int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0)prime.push_back(i);
		for (int j = i * 2; j <= n; j += i) {
			arr[j] = 1;
		}
	}
	if (prime.size() != 0) {
		int left = 0; int right = 0;
		int temp = prime[left];
		int answer = 0;
		while (left <= right) {
			if (temp == n) {
				answer++;
				right++;
				if (left == prime.size() || right == prime.size())break;
				temp += prime[right];
			}
			else if (temp < n) {
				right++;
				if (left == prime.size() || right == prime.size())break;
				temp += prime[right];
			}
			else if (temp > n) {
				temp -= prime[left];
				left++;
				if (left == prime.size() || right == prime.size())break;
			}
		}
		cout << answer;
	}
	else cout << 0;
}