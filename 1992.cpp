#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

int b[65][65];

void divide(int x, int y, int size) {
	if (size == 1) {	//ĭ ����� 1x1
		cout << b[x][y];
		return;
	}

	int onlyOne = 1;
	int onlyZero = 1;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (b[i][j] == 0) onlyOne = 0;	//�ϳ��� 0�� ������ 1�� �ȵ��ݾ�
			if (b[i][j] == 1) onlyZero = 0;
		}
	}

	if (onlyOne == 1) {	// �� 1�̸�
		cout << 1;
		return;
	}
	if (onlyZero == 1) {	//�� 0�̸�
		cout << 0;
		return;
	}

	cout << "(";
	divide(x, y, size / 2);	//���� ��
	divide(x, y + size / 2, size / 2);	//������ ��
	divide(x + size / 2, y, size / 2);	//���� �Ʒ�
	divide(x + size / 2, y + size / 2, size / 2);	//������ �Ʒ�
	cout << ")";

}

int main() {

	int N;
	cin >> N;

	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			b[i][j] = temp - '0';
		}
	}


	divide(0, 0, N);


	return 0;
}