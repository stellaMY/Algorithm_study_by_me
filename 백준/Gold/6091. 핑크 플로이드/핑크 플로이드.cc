#include <iostream>
#include <vector>
using namespace std;

/*
int INF = 1000000;

    int a[4][4] = {
      { 0, 5, INF, 8 },
      { 7, 0, 9, INF },
      { 2, INF, 0, 4 },
      { INF, INF, 3, 0 }
    };

    // 시간복잡도 V^3
    for (int k = 0; k < 4; k++)  // k 는 거쳐가는 정점
        for (int i = 0; i < 4; i++)  // i 는 행 (출발 정점)
            for (int j = 0; j < 4; j++)  // j 는 열 (도착 정점)
                if (a[i][k] + a[k][j] < a[i][j])  // 점화식 distance[i,j] = min(distance[i,j], distance[i,n] + distance[n,j])
                    a[i][j] =min( a[i][k], a[k][j]);
*/

int n;
int tree[2000][2000];
int temp[2000][2000];
vector<int>final[2000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> tree[i][j];
            tree[j][i] = tree[i][j];
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            flag = 0;
            if (tree[i][j] == 0)continue;
            for (int k = 0; k < n; k++) {
                if (tree[i][k] == 0 || tree[k][j] == 0)continue;
                if (tree[i][j] == tree[i][k] + tree[k][j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)temp[i][j] = 0;
            else temp[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (temp[i][j] == 1)
                final[i].push_back(j+1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << final[i].size() << " ";
        for (int j = 0; j < final[i].size(); j++) {
            cout << final[i][j] << " ";
        }
        cout << "\n";
    }
}