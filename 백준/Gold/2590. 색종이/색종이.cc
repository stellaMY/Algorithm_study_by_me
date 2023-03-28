#include <iostream>
using namespace std;

int paper[7];

int main() {
	for (int i = 0; i < 6; i++) {
		cin >> paper[i + 1];
	}
	int final = 0;
	int restone = 0;
	int resttwo = 0;
	int restthreeone = 0;
	int restthreetwo = 0;
	if (paper[6] != 0) {
		final += paper[6];
	}
	if (paper[5] != 0) {
		final += paper[5];
		restone += paper[5] * 11;
	}
	if (paper[4] != 0) {
		final += paper[4];
		resttwo += paper[4] * 5;
	}
	if (paper[3] != 0) {
		final += paper[3] / 4;
		if (paper[3] % 4 != 0) {
			final++;
			if (paper[3] % 4 == 1) {
				restthreeone += 27;
				restthreetwo += 5;
			}
			if (paper[3] % 4 == 2) {
				restthreeone += 18;
				restthreetwo += 3;
			}
			if (paper[3] % 4 == 3) {
				restthreeone += 9;
				restthreetwo += 1;
			}
		}
	}
	int resttwoone = 0;
	if (paper[2] != 0) {
		if (paper[2] > resttwo) {
			paper[2] -= resttwo;
			resttwo = 0;
		}
		else {
			resttwo -= paper[2];
			paper[2] = 0;
		}
		while(paper[2] != 0 && restthreetwo !=0) {
			paper[2] --;
			restthreetwo--;
			restthreeone -= 4;
		}
		if (paper[2] > 0) {
			final += paper[2] / 9;
			if (paper[2] % 9 != 0) {
				final++;
				resttwoone +=(9-( paper[2] % 9)) * 4;
			}
		}
	}
	if (paper[1] != 0) {
		paper[1] -= restone;
		while (paper[1] > 0 && restthreeone != 0) {
			paper[1]--;
			restthreeone--;
		}
		while (paper[1] > 0 && resttwoone != 0) {
			paper[1]--;
			resttwoone--;
		}
		while (paper[1] > 0 && resttwo != 0) {
			paper[1]-=4;
			resttwo--;
		}
		while (paper[1] > 0) {
			final++;
			paper[1]-=36;
		}
	}
	cout << final;
}