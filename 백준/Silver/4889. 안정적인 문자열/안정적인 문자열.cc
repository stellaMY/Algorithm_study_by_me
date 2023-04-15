#include <iostream>
#include <cmath>
using namespace std;

string str;
int one = 0;
int two = 0;
int answer;

void check(int start, int end) {
	one = 0;
	two = 0;
	for (int j = 0; j < str.size(); j++) {
		if (str[j] == '{')one++;
		else one--;
		if (one < 0) {
			answer++;
			one+=2;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	int t=1;
	while (1) {
		cin >> str;
		if (str[0] == '-')break;
		cout << t << ". ";
		answer = 0;
		check(0, str.size());
		if (one != 0)answer += one / 2;
		cout << answer << "\n";
		t++;
	}
}