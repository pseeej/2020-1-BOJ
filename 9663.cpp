#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

int N;
int* stack;
int res = 0;

int isValid(int row) {

	for (int i = 0; i < row; i++) {
		//���μ��� Ȯ��
		if (stack[row] == stack[i])
			return 0;
		//�밢�� Ȯ��
		if (abs(stack[row] - stack[i]) == (row - i)) {
			return 0;
		}
	}

	return 1;
}

void loop(int num) {
	if (num == N)
		res += 1;
	else {
		for (int i = 0; i < N; i++) {
			stack[num] = i;
			if (isValid(num))
				loop(num+1);
		}
	}
}

int main() {

	cin >> N;
	stack = new int[N];

	loop(0);

	cout << res;

	delete[] stack;

	return 0;
}