#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<string>calc;
vector<long long>num_calc;
vector<long long>num_calc2;
vector<char>char_calc;
vector<char>char_calc2;

void change_num(string str) {
	long long num = 0;
	for (int i = 0; i < str.size(); i++) {
		num += (str[i] - '0') * pow( 10, str.size() - i-1);
	}
	num_calc.push_back(num);
}

int main() {
	string str;
	cin >> str;
	int flag = 0;
	string num;
	for (int i = 0; i < str.size(); i++) {
		if (flag == 2)break;
		if (str[i] == 'Z') {
			flag = 0;
			string now = str.substr(i, 4);
			if (now != "ZERO") {
				flag = 2;
			}
			num += '0';
			i += 3;
		}
		else if (str[i] == 'O') {
			flag = 0;
			string now = str.substr(i, 3);
			if (now != "ONE") {
				flag = 2;
			}
			num += '1';
			i += 2;
		}
		else if (str[i] == 'T') {
			flag = 0;
			if (str[i + 1] == 'H') {
				string now = str.substr(i, 5);
				if (now != "THREE") {
					flag = 2;
				}
				num += '3';
				i += 4;
			}
			else if (str[i + 1] == 'W') {
				string now = str.substr(i, 3);
				if (now != "TWO") {
					flag = 2;
				}
				num += '2';
				i += 2;
			}
		}
		else if (str[i] == 'F') {
			flag = 0;
			if (str[i + 1] == 'O') {
				string now = str.substr(i, 4);
				if (now != "FOUR") {
					flag = 2;
				}
				num += '4';
				i += 3;
			}
			else if (str[i + 1] == 'I') {
				string now = str.substr(i, 4);
				if (now != "FIVE") {
					flag = 2;
				}
				num += '5';
				i += 3;
			}
		}
		else if (str[i] == 'S') {
			flag = 0;
			if (str[i + 1] == 'I') {
				string now = str.substr(i, 3);
				if (now != "SIX") {
					flag = 2;
				}
				num += '6';
				i += 2;
			}
			else if (str[i + 1] == 'E') {
				string now = str.substr(i, 5);
				if (now != "SEVEN") {
					flag = 2;
				}
				num += '7';
				i += 4;
			}
		}
		else if (str[i] == 'E') {
			flag = 0;
			string now = str.substr(i, 5);
			if (now != "EIGHT") {
				flag = 2;
			}
			num += '8';
			i += 4;
		}
		else if (str[i] == 'N') {
			flag = 0;
			string now = str.substr(i, 4);
			if (now != "NINE") {
				flag = 2;
			}
			num += '9';
			i += 3;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == 'x' || str[i] == '=' || str[i] == '/') {
			if (i == 0)flag = 2;
			if (flag == 1) {
				flag = 2;
			}
			if(!num.empty())calc.push_back(num);
			string here;
			here += str[i];
			calc.push_back(here);
			if(flag!=2)flag = 1;
			num.clear();
			if (str[i] == '=' && i != str.size() - 1)flag = 2;
		}
		else {
			flag = 2;
		}
		if (str[i] != '=' && i == str.size() - 1)flag = 2;
	}
	if (flag == 2)cout << "Madness!";
	else {
		for (int i = 0; i < calc.size(); i++) {
			if (calc[i] != "+" && calc[i] != "-" && calc[i] != "/" && calc[i] != "x" && calc[i] != "=") {
				change_num(calc[i]);
				cout << num_calc[num_calc.size() - 1];
			}
			else {
				char_calc.push_back(calc[i][0]);
				cout << calc[i][0];
			}
		}
		cout << "\n";
		int check=0;
		for (int i = 0; i < char_calc.size(); i++) {
			char_calc2.push_back(char_calc[i]);
			num_calc2.push_back(num_calc[i]);

		}
		long long final = num_calc2[0];
		for (int i = 0; i < char_calc2.size()-1; i++) {
			if (char_calc2[i] == '+')final += num_calc2[i + 1];
			else if (char_calc2[i] == 'x')final *= num_calc2[i + 1];
			else if (char_calc2[i] == '/')final /= num_calc2[i + 1];
			else final -= num_calc2[i + 1];
		}
		string result = to_string(final);
		string real_final;
		for (int i = 0; i < result.size(); i++) {
			if (result[i] == '-')real_final += '-';
			else if (result[i] == '0')real_final += "ZERO";
			else if (result[i] == '1')real_final += "ONE";
			else if (result[i] == '2')real_final += "TWO";
			else if (result[i] == '3') {
				real_final += "THR"; real_final += "EE";
			}
			else if (result[i] == '4')real_final += "FOUR";
			else if (result[i] == '5')real_final += "FIVE";
			else if (result[i] == '6')real_final += "SIX";
			else if (result[i] == '7') {
				real_final += "SEVEN";
			}
			else if (result[i] == '8') {
				real_final += "EIGHT";
			}
			else if (result[i] == '9')real_final += "NINE";
		}
		cout << real_final;
	}
}