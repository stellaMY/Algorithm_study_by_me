#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int arr[1001][1001];
struct node {
    int y, x, cnt, num;
};
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };
int final;
int visited[1001][1001] = { 0 };
int visiteds[1001][1001] = { 0 };
int num[1001][1001] = { 0 };
int counts[1000001] = { 0 };
int number = 0;

void shapes(int y, int x) {
    int ones = 1;
    queue<node>q;
    queue<int>thiss;
    visited[y][x] = 1;
    q.push({ y, x });
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if (ny == y && nx == x)continue;
            if (counts[num[ny][nx]] == 1)continue;
            if (arr[ny][nx] == 0)continue;
            if (visiteds[ny][nx] != 0) {
                ones += visiteds[ny][nx];
                counts[num[ny][nx]] = 1;
                thiss.push(num[ny][nx]);
                continue;
            }
            q.push({ ny, nx });
        }
    }
    if (final < ones)final = ones;
    while (!thiss.empty()) {
        int now = thiss.front();
        thiss.pop();
        counts[now] = 0;
    }
}

void shapess(int y, int x) {
    queue<node>q;
    queue<node>qq;
    int ones = 1;
    visited[y][x] = 1;
    q.push({ y, x });
    qq.push({ y, x });
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if (visited[ny][nx] == 1)continue;
            if (arr[ny][nx] == 0)continue;
            visited[ny][nx] = 1;
            q.push({ ny, nx });
            ones++;
           qq.push({ ny, nx });
        }
    }
    while (!qq.empty()) {
        node now = qq.front();
        qq.pop();
        visiteds[now.y][now.x] = ones;
        num[now.y][now.x] = number;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1&&visited[i][j]==0) {
                number++;
                shapess(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                shapes(i, j);
            }
        }
    }
    cout << final;
}