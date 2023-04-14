#include <iostream>
using namespace std;

int n;
int palin[5001][5001];
int num[5001];

int palindrome(int start, int end) {
	if (start >= end)return 0;
	else if (num[start] == num[end]) {
		return palindrome(start + 1, end - 1);
	}
	else if(palin[start][end] != 0 ){
		return palin[start][end];
	}
	else {
		int right = palindrome(start + 1, end) + 1;
		int left = palindrome(start, end - 1) + 1;
		if (right < left) palin[start][end] = right;
		else palin[start][end] = left;
		return palin[start][end];
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cout << palindrome(0, n-1);
}