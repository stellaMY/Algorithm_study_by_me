#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
각 행마다 얻을 수 있는 최대 사탕수 구하기 -> dp

candy[] = 각 행마다 얻을 수 있는 최대의 사탕 수 저장
만약에 저장을 또 배열로 만들면 그 범위가 커서 시간 초과 남
=> 개당 변수로 저장하여 시간초과 없앤다

얻은 각 행 최대 값으로 dp

result[] = candy에 들어있는 각 행의 최대값으로 어떠한 줄을 선택할지를 결정

==> 행과 열을 기준으로 두번의 dp를 수행하여 최종 값을 결정한다.
*/

long long m, n;
long long candy[100001];
long long result[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> m >> n;
		if (m == 0 && n == 0)break;
		for (int i = 0; i < m; i++) {
			long long b_two;
			long long b_one;
			for (int j = 0; j < n; j++) {
				long long k = 0;
				cin >> k;
				if (j == 0) {
					b_two = k;
					b_one = k;
				}
				else if (j == 1) {
					b_one = max(k, b_two);
				}
				else {
					long long tmp = b_one;
					b_one = max(b_two + k, b_one);
					b_two = tmp;
				}
			}
			candy[i] = b_one;
		}
		for (int i = 0; i < m; i++) {
			if (i == 0)result[i] = candy[i];
			else if (i == 1)result[i] = max(candy[0], candy[1]);
			else {
				result[i] = max(result[i - 2] + candy[i], result[i - 1]);
			}
		}
		cout << result[m - 1] << "\n";
	}
}