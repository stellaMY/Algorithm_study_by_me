#include <iostream>
using namespace std;

int d, k;
int day[32];

int main() {
	cin >> d >> k;
	day[2] = 1;
	day[3] = 1;
	day[4] = 2;
	for (int i = 5; i < 32; i++) {
		day[i] = day[i - 1] + day[i - 2];
	}
	int flag = 1;
	for (int i = 1; i < k / day[d - 1]; i++) {
		for (int j = i; j < k / day[d - 1]; j++) {
			if (k == day[d-1] * (i + j) + day[d - 2] * j) {
				cout << i << "\n" << j;
				flag = 0;
				break;
			}
		}
		if (flag == 0)break;
	}
}
