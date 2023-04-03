#include <iostream>
using namespace std;

int dp[3][10001];

int main() {
    dp[0][1] = 1;
    dp[0][2] = 1;
    dp[1][2] = 1;
    dp[0][3] = 2;
    dp[2][3] = 1;
    for (int i = 4; i < 10001; i++) {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1];
        if (i % 3 == 0)dp[2][i] = 1;
        if (i % 2 == 0) {
            dp[1][i]++;
            dp[1][i] += (i - 2) / 3 / 2;
        }
        int k = i - 3;
        if (k % 2 == 0) {
            int last = k / 2;
            if (last > 3) {
                if (last % 3 != 0) {
                    dp[1][i] += last / 3;
                    dp[1][i] ++;
                }
                else {
                    dp[1][i] += last / 3;
                }
            }
            else if (last <= 3)dp[1][i]++;
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        cout << dp[0][num] + dp[1][num] + dp[2][num] << "\n";
    }
}