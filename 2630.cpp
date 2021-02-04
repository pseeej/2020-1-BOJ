#pragma warning(disable:4996)
#include <iostream>
#include <cmath>
using namespace std;

int ones = 0;
int zeros = 0;

int divide(int** arr, int x, int y, int h) {
	if(h==1){	//�������� ũ�Ⱑ 1X1�϶�
		if (arr[x][y]) ones++;	//1�� ä���������� 1 ���� ���ϰ�
		else zeros++;	//0�̸� 0 ������ �߰�
		return arr[x][y];
	}

	int num = 0;
	// �� ���� ��� �ʿ�. �����¿�,,~
	num += divide(arr, x, y, h / 2);
	num += divide(arr, x + h / 2, y, h / 2);
	num += divide(arr, x, y + h / 2, h / 2);
	num += divide(arr, x + h / 2, y + h / 2, h / 2);

	if (num == 4) {	//�� ĭ�� ��� 1�̸� ���� �����̰� 4���ϱ�
		ones -= 3;	//�ϳ��� ���ϱ� ���ؼ� ones���� 3�� ���ְ� ���������� 1�� ���ϰ� ��
		return 1;	//�̰� 1�� ä���� ���̴�!
	}
	if (num == 0) {	//�� ĭ�� ��� 0
		zeros -= 3;	//�ϳ��� count���ֱ� ���� zeros���� 3 ����
		return 0;	//�̰� 0���� ä���� �������� �˷���
	}

	return -100;
}

int main() {

	int N;
	cin >> N;

	int** board = new int*[N];
	for (int i = 0; i < N; i++)
		board[i] = new int[N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	divide(board, 0, 0, N);

	cout << zeros << "\n";
	cout << ones << "\n";

	for (int i = 0; i < N; i++)
		delete board[i];
	delete[] board;

	return 0;
}