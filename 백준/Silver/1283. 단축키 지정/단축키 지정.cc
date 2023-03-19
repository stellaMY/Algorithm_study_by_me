#include<iostream>
#include <string>
using namespace std;

int al[30];

int main() {
	string n;
	getline(cin, n);
	int number = stoi(n);
	for (int i = 0; i < number; i++) {
		string cmd;
		getline(cin, cmd);
		int flag = 0;
		int k = 0;
		int num = 0;
		int cnt = 0;
		int final = 0;
		int cnts = 0;
		for (int j = 0; j < cmd.size(); j++) {
			if (j == 0) {
				if (cmd[j] >= 'A' && cmd[j] <= 'Z') {
					if (al[cmd[j + k] - 'A'] == 0) {
						flag = 1;
						al[cmd[j + k] - 'A'] = 1;
						for (int l = 0; l < cmd.size(); l++) {
							if (l != j + k)cout << cmd[l];
							else cout << "[" << cmd[l] << "]";
						}
					}
				}
				else {
					if (al[cmd[j + k] - 'a'] == 0) {
						flag = 1;
						al[cmd[j] - 'a'] = 1;
						for (int l = 0; l < cmd.size(); l++) {
							if (l != j + k)cout << cmd[l];
							else cout << "[" << cmd[l] << "]";
						}
					}
				}
			}
			else if (cmd[j - 1] == ' ') {
				cnts++;
				if (cmd[j] >= 'A' && cmd[j] <= 'Z') {
					if (al[cmd[j + k] - 'A'] == 0) {
						flag = 1;
						al[cmd[j + k] - 'A'] = 1;
						for (int l = 0; l < cmd.size(); l++) {
							if (l != j + k)cout << cmd[l];
							else cout << "[" << cmd[l] << "]";
						}
					}
				}
				else {
					if (al[cmd[j + k] - 'a'] == 0) {
						flag = 1;
						al[cmd[j] - 'a'] = 1;
						for (int l = 0; l < cmd.size(); l++) {
							if (l != j + k)cout << cmd[l];
							else cout << "[" << cmd[l] << "]";
						}
					}
				}
			}
			if (flag == 1)break;
		}
		if (flag != 1) {
			for (int j = 0; j < cmd.size(); j++) {
				if (j == 0) {
					continue;
				}
				else if (cmd[j - 1] == ' ') {
					continue;
				}
				else if (cmd[j] == ' ')continue;
				if (cmd[j] >= 'A' && cmd[j] <= 'Z') {
					if (al[cmd[j + k] - 'A'] == 0) {
						flag = 1;
						al[cmd[j + k] - 'A'] = 1;
						for (int l = 0; l < cmd.size(); l++) {
							if (l != j + k)cout << cmd[l];
							else cout << "[" << cmd[l] << "]";
						}
					}
				}
				else {
					if (al[cmd[j + k] - 'a'] == 0) {
						flag = 1;
						al[cmd[j] - 'a'] = 1;
						for (int l = 0; l < cmd.size(); l++) {
							if (l != j + k)cout << cmd[l];
							else cout << "[" << cmd[l] << "]";
						}
					}
				}
				if (flag == 1)break;
			}
		}
		if (flag == 0)cout << cmd;
		cout << "\n";
	}

}