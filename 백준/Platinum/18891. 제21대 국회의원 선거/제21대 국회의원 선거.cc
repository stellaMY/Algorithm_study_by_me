#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

// 정수 300 지역구 253 비례 47
// 대표 의석 -> 비례선거 유효 3% 이상 or 지역구선거에서 5석 이상의 정당 
// 대표 의석 -> 의석할당정당 
// 1. 우선 30석 준연동 방식
// 2. 1단계에서 30석이 안되었을때 남은 좌석 병립
// 2. 1단계에서 30석이 넘었다 연동배분으로 다시 배분
// 3. 17석에 대해 병립 

int n, v;
struct node {
	string name;
	double local, get;
	int num;
	double ratio;
	double firstseat;
	int secondseat;
	int finalseat;
};
struct edge {
	double second;
	int nowsecond;
	int num;
};
vector<node>govern;
vector<node>firstget;
bool cmp(edge a, edge b) {
	if (a.nowsecond > b.nowsecond)return true;
	if (a.nowsecond < b.nowsecond)return false;
	return false;
}
bool cmp2(node a, node b) {
	if (a.finalseat > b.finalseat)return true;
	if (a.finalseat < b.finalseat)return false;
	if (a.name > b.name)return false;
	if (a.name < b.name)return true;
	return false;
}

int main() {
	double N = 300;
	cin >> n >> v;
	double all = 0;
	double person = 0;
	for (int i = 0; i < n; i++) {
		string name;
		double local, get;
		cin >> name >> local >> get;
		all += get;
		person += local;
		govern.push_back({ name, local, get });
	}
	double firstperson = 0;
	double kk = 0;
	for (int i = 0; i < n; i++) {
		govern[i].ratio = govern[i].get / all;
		if (govern[i].ratio >= 0.03 || govern[i].local >= 5) {
			kk += govern[i].local;
			firstperson += govern[i].get;
			firstget.push_back(govern[i]);
			firstget[firstget.size() - 1].num = i;
		}
	}
	//1단계
	double firsts = 0;
	for (int i = 0; i < firstget.size(); i++) {
		double nowratio = firstget[i].get / firstperson;
		double first = ((N - (253-kk)) * nowratio - firstget[i].local) / 2;
		int tmp = ((N - (253 - kk)) * nowratio - firstget[i].local) / 2;
		if (first < 1)tmp = 0;
		else {
			if (first - tmp >= 0.5)tmp++;
		}
		firsts += tmp;
		govern[firstget[i].num].firstseat = tmp;
		firstget[i].firstseat = tmp;

	}
	//2단계
	if (firsts < 30) {
		vector<edge>change;
		for (int i = 0; i < firstget.size(); i++) {
			if (firstget[i].firstseat = 0)continue;
			double second =  (30 - firsts) * firstget[i].ratio;
			int nowsecond =  (30 - firsts) * firstget[i].ratio;
			change.push_back({ second, nowsecond, firstget[i].num});
		}
		for (int i = 0; i < change.size(); i++) {
			firsts += change[i].nowsecond;
			govern[change[i].num].firstseat += change[i].nowsecond;
			change[i].second -= change[i].nowsecond;
			double k = change[i].second * 10;
			change[i].nowsecond = k;
		}
		sort(change.begin(), change.end(), cmp);
		int i = 0;
		while (firsts < 30) {
			firsts++;
			govern[change[i].num].firstseat++;
			i++;
		}
	}
	else if (firsts > 30) {
		vector<edge>change;
		for (int i = 0; i < firstget.size(); i++) {
			double second = 30 * firstget[i].firstseat / firsts;
			int nowsecond = 30 * firstget[i].firstseat / firsts;
			change.push_back({ second, nowsecond,  firstget[i].num });
			govern[change[i].num].firstseat = 0;
		}
		firsts = 0;
		for (int i = 0; i < change.size(); i++) {
			firsts += change[i].nowsecond;
			govern[change[i].num].firstseat = change[i].nowsecond;
			change[i].second -= change[i].nowsecond;
			double k = change[i].second * 10;
			change[i].nowsecond = k;
		}
		sort(change.begin(), change.end(), cmp);
		int i = 0;
		while (firsts < 30) {
			firsts++;
			govern[change[i].num].firstseat++;
			i++;
		}
	}
	//3단계
	vector<edge>change;
	for (int i = 0; i < firstget.size(); i++) {
		double second = 17 * firstget[i].ratio;
		int nowsecond = 17 * firstget[i].ratio;
		change.push_back({ second, nowsecond,  firstget[i].num });
	}
	firsts = 0;
	for (int i = 0; i < firstget.size(); i++) {
		govern[change[i].num].secondseat = change[i].nowsecond;
		firsts += change[i].nowsecond;
		change[i].second -= change[i].nowsecond;
		double k= change[i].second * 10;
		change[i].nowsecond = k;
	}
	sort(change.begin(), change.end(), cmp);
	int i = 0;
	while (firsts < 17) {
		firsts++;
		govern[change[i].num].secondseat++;
		i++;
	}
	for (int i = 0; i<n; i++) {
		govern[i].finalseat = govern[i].local + govern[i].firstseat + govern[i].secondseat;
	}
	sort(govern.begin(), govern.end(), cmp2);
	for (int i = 0; i<n; i++) {
		cout << govern[i].name << " " << govern[i].finalseat << "\n";
	}
}