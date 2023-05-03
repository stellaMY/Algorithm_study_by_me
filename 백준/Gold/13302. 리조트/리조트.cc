#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define INF 999999999

using namespace std;

int dp[101][202];

map<int, int> npos_day;
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    int n;
    cin >> n >> m;

    fill(dp[0], dp[101], INF);

    for (int i = 0; i < m; i++)
    {
        int j;
        cin >> j;
        npos_day[j] = 1;
    }

    int ans = INF;

    for (int i = 0; i < n + 1; i++) {
        if (i == 0) dp[i][0] = 0;

        else {
            for (int j = 0; j < i; j++) {
                if (npos_day[i] == 1) dp[i][j] = min(dp[i - 1][j], dp[i][j]);
                else {
                    dp[i][j] = min(dp[i - 1][j] + 10000, dp[i][j]);
                    if (j + 3 < n) dp[i][j] = min(dp[i - 1][j + 3], dp[i][j]);
                    if (i - 3 >= 0 && j - 1>= 0) dp[i][j] = min(dp[i - 3][j - 1] + 25000, dp[i][j]);
                    if (i - 5 >= 0 && j - 2 >= 0) dp[i][j] = min(dp[i - 5][j - 2] + 37000, dp[i][j]);
                }
                if (i == n) {
                    ans = min(ans, dp[i][j]);
                    continue;
                }
            }
        }
    }


    cout << ans;
    return 0;
}