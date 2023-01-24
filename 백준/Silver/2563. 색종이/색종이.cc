#include <iostream>
using namespace std;

int paper[101][101];

int main() {
	int n;
	int final = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				if (paper[i][j] != 1) {
					final++;
					paper[i][j] = 1;
				}
			}
		}
	}
	cout << final;
}