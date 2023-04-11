#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long n, g, k;
struct node {
	long long s, l, o;
};
vector<node> mustin;
vector<node> notin;
long long result;

long long max(long long one, long long two) {
	if (one > two)return one;
	else return two;
}

int main() {
	cin >> n >> g >> k;
	for (int i = 0; i < n; i++) {
		long long s, l, o;
		cin >> s >> l >> o;
		if (o == 0)mustin.push_back({ s, l, o });
		else notin.push_back({ s, l, o });
	}
	int left = 0;
	long long right = 2134567890;
	while (left <= right) {
		int middle = (left + right) / 2;
		long long germ = 0;
		for (int i = 0; i < mustin.size(); i++) {
			germ += mustin[i].s * max(1, middle - mustin[i].l);
		}
		for (int i = 0; i < notin.size(); i++) {
			germ += notin[i].s * max(1, middle - notin[i].l);
		}
		if (germ <= g) {
			left = middle + 1;
			result = middle;
		}
		else if (k == 0) {
			if (germ <= g) {
				left = middle + 1;
				result = middle;
			}
			else right = middle - 1;
		}
		else {
			priority_queue<long long>q;
			for (int i = 0; i < notin.size(); i++) {
				q.push( notin[i].s * max(1, middle - notin[i].l));
			}
			for (int i = 0; i < k; i++) {
				if (q.empty())break;
				germ -= q.top();
				q.pop();
			}
			if (germ <= g) {
				left = middle + 1;
				result = middle;
			}
			else right = middle - 1;
		}
	}
	cout << result;
}