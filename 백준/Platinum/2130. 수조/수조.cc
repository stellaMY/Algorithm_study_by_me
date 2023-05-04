#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double v;
struct node {
	double b, h, w, d, top;
};
vector<node>bottle;
bool cmp(node a, node b) {
	if (a.b == b.b)return a.top < b.top;
	return a.b < b.b;
}
double answer;
vector<double>minuss[1040001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int right=0;
	int left=2134567890;
	double flag = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double b, h, w, d;
		cin >> b >> h >> w >> d;
		bottle.push_back({ b, h, w, d, b+h});
		bottle.push_back({ b + h, h, w, d, 0 });
		if (b + h > right)right = b + h;
		if (b < left)left = b;
		flag += h * w * d;
	}
	cin >> v;

	if (flag < v)flag = 1;
	else if (flag == v) {
		answer = right;
		flag = 2;
	}
	else flag = 0;
	if (flag == 0) {
		sort(bottle.begin(), bottle.end(), cmp);
		int size = bottle[0].w * bottle[0].d;
		int nowheight = bottle[0].b;
		answer = nowheight;
		int k = bottle[0].h + bottle[0].b;
		minuss[k].push_back(size);
		for (int i = 1; i < n*2; i++) {
			k = bottle[i].h + bottle[i].b;
			if (bottle[i].top == 0) {
				if ((bottle[i].b - nowheight) * size >= v) {
					double height = v / size;
					int k = height * 100000000;
					double kk = k;
					double height2 = kk / 100000000;
					answer = nowheight + height2;
					break;
				}
				v -= size * (bottle[i].b-nowheight);
				size -= bottle[i].d * bottle[i].w;
			}
			else {
				if ((bottle[i].b - nowheight) * size >= v) {
					double height = v / size;
					int k = height * 100000000;
					double kk = k;
					double height2 = kk / 100000000;
					answer = nowheight + height2;
					break;
				}
				v -= size * (bottle[i].b - nowheight);
				size += bottle[i].d * bottle[i].w;
			}
			nowheight = bottle[i].b;
		}
	}
	if (flag == 1)cout << "OVERFLOW";
	else {
		cout<<fixed;
		cout.precision(2);
		cout << answer;
	}
}