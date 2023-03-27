#include <iostream>
#include <unordered_map>
using namespace std;

int r, c;
char map[1001][1001];

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++) {
            map[i][j] = str[j];
        }
    }
    int k = 0;
    int final = -1;
    int flag = 0;
    int left = 0;
    int right = r;
    while (left <= right) {
        unordered_map<string, string>strings;
        flag = 0;
        int middle = (left + right) / 2;
        for (int i = 0; i < c; i++) {
            string str;
            for (int j = middle; j < r; j++) {
                str += map[j][i];
            }
            if (strings[str] == "YES") {
                right = middle -1;
                flag = 1;
                break;
            }
            strings[str] = "YES";
        }
        if (flag == 0) {
            final = middle;
            left = middle +1;
        }
    }
    cout << final;
}