#include <iostream>
using namespace std;

int arr[100001];
int n, m;

int main() {
	cin >> n >> m;
	int answer = 2134567890;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] >= m)answer = 1;
	}
	int front = 0;
	int last = 0;
	int temp = arr[0];
	if (answer == 2134567890) {
		while (front < n&&last<n) {
			if (temp < m) {
				last++;
				if (last == n)break;
				temp += arr[last];
			}
			else {
				temp -= arr[front];
				front++;
			}
			if (temp >= m && answer > -front + last + 1)answer = last - front + 1;
		}
	}
	if (answer == 2134567890)cout << 0;
	else cout << answer;
}