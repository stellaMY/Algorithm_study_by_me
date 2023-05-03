#include <iostream>
using namespace std;

int n;
int now[1001];
int real[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> now[i];
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		real[i] = now[i] - num;
	}
	int start = real[0];
	int final = abs(start);
	for (int i = 0; i < n; i++) {
		if (start < 0 && real[i] < 0) {
			if (start > real[i]) {
				final += start - real[i];
			}
			start = real[i];
		}
		else if (start < 0 && real[i]>0) {
			final += real[i];
			start = real[i];
		}
		else if (start == 0 && real[i] < 0) {
			final -= real[i];
			start = real[i];
		}
		else if (start == 0 && real[i] > 0) {
			final += real[i];
			start = real[i];
		}
		else if (start > 0 && real[i] < 0) {
			final -= real[i];
			start = real[i];
		}
		else if (start > 0 && real[i] > 0) {
			if (start < real[i]) {
				final += real[i] - start;
			}
			start = real[i];
		}
		else if (real[i] == 0) {
			start = 0;
		}
	}
	cout << final;
}