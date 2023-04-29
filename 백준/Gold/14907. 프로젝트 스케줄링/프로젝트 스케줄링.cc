#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<char>alpha[26]; // 내 일을 끝내야 할 수 있는 일들
int cosst[26]; // 현재 일의 수행 시간
int beforenum[26]; // 이전에 끝내야 하는 갯수
int visited[26];  // 최종으로 할 수 있는 최소한의 시간

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i < 26; i++) {
        beforenum[i] = -1;
    }
    string one;
    // 입력의 갯수가 주어져 있지 않다
    while (!cin.eof()) {
        getline(cin, one);
        if (cin.eof())break;
        string costt;
        string before;
        int flag = 0;
        for (int i = 0; i < one.size(); i++) {
            if (one[i] == ' ')flag++;
            if (flag == 1 && one[i] != ' ')costt += one[i];
            if (flag == 2 && one[i] != ' ')before += one[i];
            if (one[i] == '\n')break;
        }
        int cost = stoi(costt);
        // 내 일을 끝내기 위해 필요한 일들을 넣어주기
        if (before.size() != 0) {
            for (int i = 0; i < before.size(); i++) {
                alpha[before[i] - 'A'].push_back(one[0]-'A');
            }
        }
        // 내 일을 수행하는 시간
        cosst[one[0] - 'A'] = cost;
        // 내 일을 끝내기 위해 필요한 일의 갯수
        beforenum[one[0] - 'A'] = before.size();
    }

    // 바로 수행할 수 있는 일들은 바로 수행
    queue<int>q;
    for (int i = 0; i < 26; i++) {
        if (beforenum[i] == 0) {
            q.push(i);
            visited[i] = cosst[i];
        }
    }

    // 수행하고 만일 일이 여러개라면 수를 줄이고 최대 시간으로 갱신한다
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < alpha[now].size(); i++) {
            if (beforenum[alpha[now][i]] > 0) {
                if (visited[alpha[now][i]] > cosst[alpha[now][i]] + visited[now]) {
                    beforenum[alpha[now][i]]--;
                    if (beforenum[alpha[now][i]] == 0) {
                        q.push(alpha[now][i]);
                    }
                    continue;
                }
                else {
                    visited[alpha[now][i]] = cosst[alpha[now][i]] + visited[now];
                    beforenum[alpha[now][i]]--;
                    if (beforenum[alpha[now][i]] == 0) {
                        q.push(alpha[now][i]);
                    }
                }
            }
        }
    }
    int final = 0;
    for (int i = 0; i < 26; i++) {
        if (visited[i] > final)final = visited[i];
    }
    cout << final;
}
