#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
struct node {
    int start, end, people;
};
vector<node>room;
node dp[100001];
bool cmp(node a, node b) {
    if (a.end < b.end)return true;
    if (a.end > b.end)return false;
    if (a.start < b.start)return true;
    if (a.start > b.start)return false;
    if (a.people < b.people)return false;
    if (a.people > b.people)return true;
    return false;
}
struct edge {
    int num, people;
};
int result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int start, end, people;
        cin >> start >> end >> people;
        room.push_back({ start, end, people });
    }
    sort(room.begin(), room.end(), cmp);

    dp[0].people = room[0].people;
    dp[0].start = room[0].start;
    if (room[1].start < room[0].end) {
        if (dp[0].people > room[1].people) {
            dp[1].people = dp[0].people;
            dp[1].start = dp[0].start;
        }
        else {
            dp[1] = room[1];
        }
    }
    else dp[1].people = dp[0].people + room[1].people;
    for (int i = 2; i < n; i++) {
        int now = 0;
        for (int j = max(0, i - n / 2); j < i; j++) {
            if (room[j].end > room[i].start)break;
            if (now < dp[j].people)now = dp[j].people;
        }
        dp[i].people = max(dp[i - 1].people, now + room[i].people);
        dp[i].start = room[i].start;
    }
    int resut = 0;
    for (int i = 0; i < n; i++) {
        if (result < dp[i].people)result = dp[i].people;
    }
    cout << result;
}