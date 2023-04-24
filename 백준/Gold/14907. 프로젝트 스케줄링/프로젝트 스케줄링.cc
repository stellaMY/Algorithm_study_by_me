#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<char>alpha[26];
int cosst[26];
int beforenum[26];
int visited[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i < 26; i++) {
        beforenum[i] = -1;
    }
    string one;
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
        if (before.size() != 0) {
            for (int i = 0; i < before.size(); i++) {
                alpha[before[i] - 'A'].push_back(one[0]-'A');
            }
        }
        cosst[one[0] - 'A'] = cost;
        beforenum[one[0] - 'A'] = before.size();
    }
    queue<int>q;
    for (int i = 0; i < 26; i++) {
        if (beforenum[i] == 0) {
            q.push(i);
            visited[i] = cosst[i];
        }
    }
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