#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double v;
// 받은 인자들과 수조가 어느 높이까지 오는지 넣기
struct node {
	double b, h, w, d, top;
};
vector<node>bottle;
bool cmp(node a, node b) {
	if (a.b == b.b)return a.top < b.top;
	return a.b < b.b;
}
double answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 가장 높은 위치 확인
	int right=0;
	// 전체 부피가 같은지 큰지 작은지 확인
	double flag = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double b, h, w, d;
		cin >> b >> h >> w >> d;
		bottle.push_back({ b, h, w, d, b+h});
		// 수조가 끝나는 위치 확인
		bottle.push_back({ b + h, h, w, d, 0 });
		if (b + h > right)right = b + h;
		flag += h * w * d;
	}
	cin >> v;

	// 만약 넘어간다면 overflow
	if (flag < v)flag = 1;
	// 같다면 그냥 가장 높은 높이
	else if (flag == v) {
		answer = right;
		flag = 2;
	}
	// 아니라면 확인
	else flag = 0;
	if (flag == 0) {
		// 가장 아래부터 올라가면서 확인
		sort(bottle.begin(), bottle.end(), cmp);
		// 현재 위치에서 가지고 있는 크기
		int size = bottle[0].w * bottle[0].d;
		// 현재의 가장 낮은 높이
		int nowheight = bottle[0].b;
		answer = nowheight;
		int k = bottle[0].h + bottle[0].b;
		for (int i = 1; i < n*2; i++) {
			k = bottle[i].h + bottle[i].b;
			// 만약 새로운 수조가 아닌 끝나는 곳이라면
			if (bottle[i].top == 0) {
				// 그 높이까지의 부피 확인
				// 만약 넘어가면 정답 확인
				if ((bottle[i].b - nowheight) * size >= v) {
					double height = v / size;
					int k = height * 100000000;
					double kk = k;
					double height2 = kk / 100000000;
					answer = nowheight + height2;
					break;
				}
				// 아니라면 그 높이까지의 부피 빼고 
				// 크기에서도 현재의 크기 빼기
				v -= size * (bottle[i].b-nowheight);
				size -= bottle[i].d * bottle[i].w;
			}
			// 만약 새로운 수조라면
			else {
				// 그 높이까지의 부피 확인
				// 만약 넘어가면 정답 확인
				if ((bottle[i].b - nowheight) * size >= v) {
					double height = v / size;
					int k = height * 100000000;
					double kk = k;
					double height2 = kk / 100000000;
					answer = nowheight + height2;
					break;
				}
				// 아니라면 그 높이까지의 부피 빼고
				// 새로운 수조의 크기 더해주기
				v -= size * (bottle[i].b - nowheight);
				size += bottle[i].d * bottle[i].w;
			}
			// 새로운 가장 낮은 높이 갱신 
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
