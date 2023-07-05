#include <iostream>
#include <cmath>
using namespace std;

int n;
int player[100001];
int answer[100001];
struct node {
	int num, location;
};
node number[1000001];
int large;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> player[i];
		number[player[i]] = {1, i};
		if (player[i] > large)large = player[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = player[i]*2; j <= large; j+=player[i]) {
			if (j%player[i] == 0 && number[j].num == 1) {
				answer[number[j].location]--;
				answer[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}
}