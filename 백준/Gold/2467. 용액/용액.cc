#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[100001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int left = 0;
	int right = n-1;
	int small = arr[0];
	int large = arr[n-1];
	int temp = small + large;
	int answer = temp;
	while (left < right) {
		if (temp == 0)break;
		if (temp > 0) {
			right--;
			if (left == right)break;
			if (abs(answer) > abs(arr[left] + arr[right])) {
				small = arr[left];
				large = arr[right];
				temp = arr[left] + arr[right];
				answer = temp;
			}
			temp = arr[left] + arr[right];
		}
		else {
			left++;
			if (left == right)break;
			if (abs(answer) > abs(arr[left] + arr[right])) {
				small = arr[left];
				large = arr[right];
				temp = arr[left] + arr[right];
				answer = temp;
			}
			temp = arr[left] + arr[right];
		}
	}
	cout << small << " " << large;
}