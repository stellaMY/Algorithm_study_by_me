#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
struct node {
	int color, size;
};
struct edge {
	int size, snwjr;
};
vector<node>ball;
vector<edge>final[200001];
int finalresult[200001];
vector<node>finalcolor[200001];
bool operator <(node a, node b) {
	if (a.size > b.size)return true;
	if (a.size < b.size)return false;
	if (a.color > b.color)return true;
	if (a.color < b.color)return false;
	return false;
}
//컬러별 작은 사이즈 순으로 정렬
priority_queue<node>things;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int color, size;
		cin >> color >> size;
		ball.push_back({ color, size });
		things.push({ color, size });
	}
	int nowhere = 0;
	while (!things.empty()) {
		//작은 사이즈부터 뽑음
		node now = things.top();
		things.pop();
		//만약 이전과 같은 크기라면 누적에 현재 사이즈 추가
		if (nowhere - 2 == now.size) {
			finalresult[now.size + 1] += now.size;
		}
		//다른 크기라면 이전 크기부터 현재 크기까지 누적값 넣기
		else {
			for (int i = nowhere; i <= now.size; i++) {
				finalresult[i] = finalresult[nowhere-1];
			}
			finalresult[now.size + 1] += finalresult[now.size] + now.size;
		}
		//다음 인덱스 시작
		nowhere = now.size + 2;
		//컬러별로 누적 사이즈 final에 넣기
		if (final[now.color].size() == 0) {
			final[now.color].push_back({ now.size, now.size });
			finalcolor[now.color].push_back({ now.size, 0});
		}
		//만일 이전과 사이즈가 같으면 누적 추가
		else if (final[now.color][final[now.color].size() - 1].size == now.size) {
			for (int i = final[now.color].size() - 1; i >= 0; i--) {
				if (final[now.color][i].size == now.size) {
					final[now.color][i].snwjr += now.size;
				}
				else break;
			}
			final[now.color].push_back({ now.size,final[now.color][final[now.color].size() - 1].snwjr });
			int sized = final[now.color].size();
			//finalcolor[now.color].push_back({ now.size, sized-1});
		}
		else {
			final[now.color].push_back({ now.size, now.size + final[now.color][final[now.color].size() - 1].snwjr });
			int sized = final[now.color].size();
			finalcolor[now.color].push_back({ now.size, sized - 1 });
		}
	}
	//받은 순서대로 뽑으면서 확인
	//ball에 몇번째 아이인지만 들어있으면 된다.
	for (int j = 0; j < n; j++) {
		node now = ball[j];
		int finals = finalresult[now.size];
		for (int i = 0; i < finalcolor[now.color].size(); i++) {
			if (finalcolor[now.color][i].color == now.size) {
				if (finalcolor[now.color][i].size == 0)break;
				int plz = finalcolor[now.color][i].size-1;
				/*for (int k = finalcolor[now.color][i].size-1; k >= 0; k--) {
					if (now.size == final[now.color][k].size) {
						plz--;
					}
					else break;
				}*/
				finals -= final[now.color][plz].snwjr;
				if (plz+2<final[now.color].size() && final[now.color][plz + 2].size != now.size) {
					finalcolor[now.color].erase(finalcolor[now.color].begin() + i);
				}break;
			}
		}
		cout << finals << "\n";
	}
}