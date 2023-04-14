#include <iostream>
#include <queue>
using namespace std;

int n, h, w, m, k;
int map[501][501]; // 험난도 맵
int withmap[501][501]; // 유닛들이 어디에 존재하는지 확인
int fightmap[501][501]; // 각 유닛들이 전투 중인지 확인
struct edge {
    int y, x, gogo, size;
};
edge unit[70001]; // 각 유닛 들의 모음 
int type[10]; // 타입별로의 험난도 
int ydir[] = { 0,0,1,-1 };
int xdir[] = { 1,-1,0,0 };
int visited[501][501];

// 가려는 길 주위에 다른 세력이 있는지 확인 
// 만일 확인되면 1을 반환, 아니라면 0
// 만약에 길이 없으면 거기서 전투를 해야 한다?
int check_again(int u, int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + ydir[i];
        int nx = x + xdir[i];
        if (ny < 0 || nx < 0 || ny >= h || nx >= w)continue;
        if (withmap[ny][nx] != 0) {
            if (unit[withmap[ny][nx]].size == unit[u].size)continue;
            else {
                return 1;
            }
        }
    }
    return 0;
}

//목표지점으로 최단거리로 가는 방법 확인
void playgame(int u, int a, int b) {
    queue<edge>q;
    q.push({ unit[u].y, unit[u].x , 0 });
    while (!q.empty()) {
        edge now = q.front();
        q.pop();
        if (now.y == a && now.x == b)continue;
        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w)continue;
            if (withmap[ny][nx]!=0&&unit[withmap[ny][nx]].size != unit[u].size)continue;
            if (visited[ny][nx] <= now.gogo + type[map[ny][nx]])continue;
            if (type[map[ny][nx]] == -1)continue;
            if (ny == a && nx == b) {
                visited[ny][nx] = now.gogo + type[map[ny][nx]];
                continue;
            }
            if (now.gogo + type[map[ny][nx]] >= unit[u].gogo)continue;
            int check = check_again(u, ny, nx);
            if (check == 1)continue;
            visited[ny][nx] = now.gogo + type[map[ny][nx]];
            q.push({ ny, nx, now.gogo + type[map[ny][nx]] });
        }
    }
    if (visited[a][b] <= unit[u].gogo) {
        withmap[unit[u].y][unit[u].x] = 0;
        unit[u].y = a;
        unit[u].x = b;
        withmap[a][b] = u;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> type[i + 1];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int gogo, size, y, x;
        cin >> gogo >> size >> y >> x;
        withmap[y][x] = i+1;
        unit[i + 1] = { y, x, gogo, size };
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int u, a, b;
        cin >> u >> a >> b;
        if (withmap[a][b] != 0)continue; // 만일 도착지에 사람 있으면 다음으로
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                visited[i][j] = 2134567890;
            }
        }
        playgame(u, a, b);
    }
    for (int i = 1; i <= m; i++) {
        cout << unit[i].y << " " << unit[i].x << "\n";
    }
}