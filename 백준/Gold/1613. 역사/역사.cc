#include <iostream>
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

int n, k, s;
int history[401][401];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int befor, after;
        cin >> befor >> after;
        befor--;
        after--;
        history[befor][after] = -1;
        history[after][befor] = 1;
    }

    //플로이드와샬
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (history[i][k] == 1 && history[k][j] == 1) {
                    history[i][j] = 1;
                    history[j][i] = -1;
                }
            }
        }
    }

    cin >> s;
    for (int i = 0; i < s; i++) {
        int one, two;
        cin >> one >> two;
        one--;
        two--;
        cout << history[one][two]<<"\n";
    }
}