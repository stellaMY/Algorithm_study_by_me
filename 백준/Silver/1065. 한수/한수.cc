#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n;

int main() {
    cin >> n;
    int final = 0;
    for (int i = 1; i <= n; i++) {
        string str = to_string(i);
        if (str.size() > 2) {
            int minuss = str[1] - str[0];
            for (int j = 1; j < str.size() - 1; j++) {
                if (str[j + 1] - str[j] != minuss)break;
                if (j == str.size() - 2)final++;
            }
        }
        else final++;
    }
    cout << final;
}