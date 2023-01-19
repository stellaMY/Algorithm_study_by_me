#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
long long arr[51];
int main() {
	ios_base::sync_with_stdio;
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int maxval = 0;
	int final = 0;

	for (int i = 0; i < n; i++) {
		int flag = 0;
		int flag2 = 0;
		long long now = arr[i];
		int cnt = 0;
		double tiltminus = 2134567890213456789;
		double tiltplus = 2134567890213456789;
		double tiltminusright = -2134567890213456789;
		double tiltplusright = -2134567890213456789;
		for (int j = i - 1; j >= 0; j--) {
			double tiltnow = 0.00;
			if (arr[j] < now && flag==0) {
				float it = i - j;
				tiltnow = (arr[i] - arr[j]) / it;
				if (tiltnow < tiltminus) {
					cnt++;
					tiltminus = tiltnow;
				}

			}
			if (arr[j] >= now) {
				float it = i - j;
				tiltnow = (arr[i] - arr[j]) / it;
				if (tiltnow < tiltplus) {
					cnt++;
					tiltplus = tiltnow;
				}
				flag = 1;
			}
			
		}
		for (int j = i + 1; j < n; j++) {
			double tiltnow = 0.00;
			if (arr[j] < now&& flag2==0) {
				float it = j - i;
				tiltnow = (arr[j] - arr[i]) / it;
				if (tiltnow > tiltminusright) {
					cnt++;
					tiltminusright = tiltnow;
				}
			}
			if (arr[j] >= now) {
				float it = j - i;
				tiltnow = (arr[j] - arr[i]) / it;
				if (tiltnow > tiltplusright) {
					cnt++;
					tiltplusright = tiltnow;
				}
				flag2 = 1;
			}
		}
		if (cnt > maxval) {
			maxval = cnt;
			final = i + 1;
		}
	}cout << maxval;
}
