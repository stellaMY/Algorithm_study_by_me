#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string apple, cube;
vector<char>gual;
vector<char>cual;
char final[300001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> apple >> cube;
    for (int i = 0; i < apple.size(); i++) {
        gual.push_back(apple[i]);
    }
    for (int i = 0; i < cube.size(); i++) {
        cual.push_back(cube[i]);
    }
    // 결과 문장의 시작과 끝
    int left = 0;
    int right = apple.size() - 1;
    // 구사과가 사용할 알파벳의 시작과 끝
    int gucnt = apple.size() / 2 - 1;
    int gucntf = 0;
    // 큐브가 사용할 알파벡의 시작과 끝
    int cucnt = apple.size() / 2;
    int cucntb = apple.size() - 1;
    if (apple.size() % 2 == 1) {
        gucnt++;
        cucnt++;
    }
    sort(gual.begin(), gual.end());
    sort(cual.begin(), cual.end());

    for (int i = 0; i < apple.size() / 2; i++) {
        /*
        구사과가 가지고 있는 알파벳이 큐브가 가지고 있는 알파벳보다 무조건 크다면
        구사과가 가지고 있는 알파벳중 가장 큰 것부터 맨 뒤에 놓는 것이
        사전 순으로 가장 작게 만든다
        ?? 그 비교를 '>'로 할경우는 오답이 나오고 '>=' 로 한다면 정답이다 
        => 그 이유는??
        */
        if (gual[gucntf] >= cual[cucntb]) {
            final[right] = gual[gucnt];
            right--;
            gucnt--;
        }
        else {
            final[left] = gual[gucntf];
            left++;
            gucntf++;
        }
        /*
        큐브가 가지고 있는 알파벳이 구사과가 가지고 있는 알파벳보다 무조건 작다면
        큐브가 가지고 있는 알파벳중 가장 작은 것부터 맨 앞에 놓는 것이
        사전 순으로 가장 크게 만든다
        */  
        if (cual[cucntb] <= gual[gucntf]) {
            final[right] = cual[cucnt];
            right--;
            cucnt++;
        }
        else {
            final[left] = cual[cucntb];
            left++;
            cucntb--;
        }
    }
    // 만약 빈곳이 있다면 구사과가 놓은 자리니까 구사과의 놓지 않은 알파벳 중 가장 
    // 작은 아이를 넣는다
    for (int i = 0; i < apple.size(); i++) {
        if (final[i] == 0)final[i] = gual[gucntf];
        cout << final[i];
    }
}
