#include <iostream>
using namespace std;

int al[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int name[4000][4001];

int main() {
	string him, her;
	cin >> him >> her;
	int p = 0;
	for (int i = 0; i < him.size(); i++) {
		name[0][p] = al[him[i] - 'A']; 
		name[0][p + 1] = al[her[i] - 'A'];
		p+=2;
	}
	int k = 1;
	for (int i = 1; i < him.size() + her.size() - 1; i++) {
		for (int j = 0; j < him.size() + her.size() - k; j++) {
			name[i][j] = name[i - 1][j] + name[i - 1][j + 1];
			if (name[i][j] >=10)name[i][j] -= 10;
		}
		k++;
	}
	cout << name[him.size() + her.size() - 1-1][0] << name[him.size() + her.size() -1- 1][1];
}