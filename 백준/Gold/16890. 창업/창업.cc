#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string apple, cube;
vector<char>gual;
vector<char>cual;
char final[300001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> apple >> cube;
    for (int i = 0; i < apple.size(); i++) {
        gual.push_back(apple[i]);
    }
    for (int i = 0; i < cube.size(); i++) {
        cual.push_back(cube[i]);
    }
    int left = 0;
    int right = apple.size() - 1;
    int gucnt = apple.size() / 2 - 1;
    int gucntf = 0;
    int cucnt = apple.size() / 2;
    int cucntb = apple.size() - 1;
    if (apple.size() % 2 == 1) {
        gucnt++;
        cucnt++;
    }
    sort(gual.begin(), gual.end());
    sort(cual.begin(), cual.end());
    for (int i = 0; i < apple.size() / 2; i++) {
        if (gual[gucntf] >= cual[cucntb]) {
            final[right] = gual[gucnt];
            right--;
            gucnt--;
        }
        else {
            final[left] = gual[gucntf];
            left++;
            gucntf++;
        }
        if (cual[cucntb] <= gual[gucntf]) {
            final[right] = cual[cucnt];
            right--;
            cucnt++;
        }
        else {
            final[left] = cual[cucntb];
            left++;
            cucntb--;
        }
    }
    for (int i = 0; i < apple.size(); i++) {
        if (final[i] == 0)final[i] = gual[gucntf];
        cout << final[i];
    }
}