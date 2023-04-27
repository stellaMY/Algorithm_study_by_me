#include <iostream>
using namespace std;

// 나뉘어지는 영역의 구간은 6가지 
// 원 세모 네모
// 원 네모 세모
// 세모 네모 원
// 세모 원 네모
// 네모 원 세모
// 네모 세모 원 
// 총 6가지 방법 중 가장 작은 횟수를 구한다

int shape[4];
int n;
int shaped[100001];
// 총 6가지 방법, 3가지 구역, 3가지 모양의 수
int tmpshape[7][4][4];
int answer =2134567890;

void change(int k, int one, int two, int three) {
	for (int i = 0; i < shape[one]; i++) {
		tmpshape[k][one][shaped[i]]++;
	}
	for (int i = shape[one]; i < shape[two] + shape[one]; i++) {
		tmpshape[k][two][shaped[i]]++;
	}
	for (int i = shape[two] + shape[one]; i < n; i++) {
		tmpshape[k][three][shaped[i]]++;
	}
	int onetotwo = tmpshape[k][one][two];
	int onetothree = tmpshape[k][one][three];
	int twotoone = tmpshape[k][two][one];
	int twotothree = tmpshape[k][two][three];
	int threetoone = tmpshape[k][three][one];
	int threetotwo = tmpshape[k][three][two];
	int final = 0;
	if (onetotwo > twotoone) {
		final += twotoone;
		onetotwo -= twotoone;
		twotoone = 0;
	}
	else {
		final += onetotwo;
		twotoone -= onetotwo;
		onetotwo = 0;
	}
	if (onetothree > threetoone) {
		final += threetoone;
		onetothree -= threetoone;
		threetoone = 0;
	}
	else {
		final += onetothree;
		threetoone -= onetothree;
		onetothree = 0;
	}
	if (twotothree > threetotwo) {
		final += threetotwo;
		twotothree -= threetotwo;
		threetotwo = 0;
	}
	else {
		final += twotothree;
		threetotwo -= twotothree;
		twotothree = 0;
	}
	final += onetotwo + twotoone + threetoone + onetothree;
	//if ((onetotwo + onetothree + twotoone + twotothree + threetoone + threetotwo + onetwoleft + onethreeleft + twothreeleft) % 2 == 1)final++;
	if (answer > final)answer = final;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> shaped[i];
		shape[shaped[i]]++;
	}
	// 원 세모 네모
	change(1, 1, 2, 3);
	// 원 네모 세모
	change(2, 1, 3, 2);
	// 세모 원 네모
	change(3, 2, 1, 3);
	// 세모 네모 원
	change(4, 2, 3, 1);
	// 네모 원 세모
	change(5, 3, 1, 2);
	// 네모 세모 원 
	change(6, 3, 2, 1);
	cout << answer;
}