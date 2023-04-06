#include <iostream>
using namespace std;

int n;
long long most_big;
long long all_money;
int flag = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long wnwjr, money;
		cin >> wnwjr >> money;
		if (all_money > wnwjr) {
			if (money < most_big) {
				all_money -= most_big;
				if (all_money > wnwjr) {
					all_money += most_big;
				}
				else all_money += money;
			}
			flag++;
		}
		else {
			if (money > most_big)most_big = money;
			all_money += money;
		}
		if (flag > 1)break;
	}
	if (flag <= 1)cout << "Kkeo-eok";
	else cout << "Zzz";
}
