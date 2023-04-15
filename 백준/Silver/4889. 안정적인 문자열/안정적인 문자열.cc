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
	int t=1;
	while (1) {
		cin >> str;
		if (str[0] == '-')break;
		cout << t << ". ";
		answer = 0;
		check(0, str.size());
		if (one != 0)answer += one / 2;
		//if (one / 2 != 0)answer++;
		cout << answer << "\n";
		/*if (str[0] == '{' && str[str.size() - 1] == '}') {
			if (one == two)cout << 0 << "\n";
			else cout << abs(one) / 2 << "\n";
		}
		else if (str[0] != '{' && str[str.size() - 1] == '}') {
			if (one == two)cout << 1 << "\n";
			else cout << abs(one) / 2 + 1 << "\n";
		}
		else if (str[0] == '{' && str[str.size() - 1] != '}') {
			if (one == two)cout << 1 << "\n";
			else cout << abs(one) / 2 + 1<< "\n";
		}
		else if (str[0] != '{' && str[str.size() - 1] != '}') {
			if (one == two)cout << 2 << "\n";
			else cout << abs(one) / 2 +2 << "\n";
		}*/
		t++;
	}
}