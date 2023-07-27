#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n;
stack<int>s;
int arr[100001];
queue<char>q;
int flag = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int num = 1;
	int dat = 0;
	while (1) {
		if (num == arr[dat]) {
			dat++;
			num++;
			q.push('+');
			while(arr[dat] < num&&!s.empty()) {
				if (s.top() != arr[dat]) {
					cout << "NO";
					flag = 1;
				}
				else {
					dat++;
					q.push('-');
					s.pop();
				}
				if (dat == n)break;
				if (flag == 1)break;
			}
			q.push('-');
			if (dat == n)break;
			if (flag == 1)break;
		}
		else if(num<=n) {
			s.push(num);
			num++;
			q.push('+');
		}
	}
	if (flag == 0) {
		while (!q.empty()) {
			cout << q.front() << "\n";
			q.pop();
		}
	}
}