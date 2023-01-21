#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int>q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == 0 && q.empty())cout << 0<<"\n";
		else if (t == 0) {
			cout << q.top()<<"\n";
			q.pop();
		}
		else q.push(t);
	}

}
