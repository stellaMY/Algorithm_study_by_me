#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string str;
    cin >> str;
    int final = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'c' && i != str.size() - 1 && str[i + 1] == '=') {
            final++;
            i++;
        }
        else if (str[i] == 'c' && i != str.size() - 1 && str[i + 1] == '-') {
            final++;
            i++;
        }
        else if (str[i] == 'd' && i != str.size() - 1 && str[i + 1] == '-') {
            final++;
            i++;
        }
        else if (str[i] == 'l' && i != str.size() - 1 && str[i + 1] == 'j') {
            final++;
            i++;
        }
        else if (str[i] == 'n' && i != str.size() - 1 && str[i + 1] == 'j') {
            final++;
            i++;
        }
        else if (str[i] == 's' && i != str.size() - 1 && str[i + 1] == '=') {
            final++;
            i++;
        }
        else if (str[i] == 'z' && i != str.size() - 1 && str[i + 1] == '=') {
            final++;
            i++;
        }
        else if (str[i] == 'd' && i != str.size() - 2 && str[i + 1] == 'z' && str[i + 2] == '=') {
            final++;
            i += 2;
        }
        else final++;
    }
    cout << final;
}