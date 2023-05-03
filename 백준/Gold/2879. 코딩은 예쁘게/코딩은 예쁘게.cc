#include <iostream>
using namespace std;

int n;
// 현재의 상태
int now[1001];
// 현재의 상태와 올바른 상태의 차이
int real[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> now[i];
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		real[i] = now[i] - num;
	}
	// 맨 앞부터 보면서 음수와 양수일 때의 경우의 수를 확인
	// 같은 수로 만들기와 다르게 더 작은 값으로 가는 경우이기 때문에
	// 계속해서 기존의 현재값이 아닌 바로 이전의 값과의 비교를 해야한다
	int start = real[0];
	int final = abs(start);
	for (int i = 0; i < n; i++) {
		// 둘다 음수일때 더 가지고 있는 값보다 더 작다면
		// 추가하고 가지고 있는 값 갱신
		if (start < 0 && real[i] < 0) {
			if (start > real[i]) {
				final += start - real[i];
			}
			start = real[i];
		}
		// 서로 반대의 값이라면 차이를 볼 것 없이 더하고 갱신
		else if (start <= 0 && real[i]>=0) {
			final += real[i];
			start = real[i];
		}
		else if (start >= 0 && real[i] <= 0) {
			final -= real[i];
			start = real[i];
		}
		// 둘다 양수일때 더 가지고 있는 값보다 더 크다면
		// 추가하고 가지고 있는 값 갱신
		else if (start > 0 && real[i] > 0) {
			if (start < real[i]) {
				final += real[i] - start;
			}
			start = real[i];
		}
	}
	cout << final;
}
