#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int wearings;
		cin >> wearings;

		string* types = new string[wearings];
		int* cntType = new int[wearings];
		for (int i = 0; i < wearings; i++)
			cntType[i] = 0;

		int index = 0;
		for (int j = 0; j < wearings; j++) {
			string temp;
			cin >> temp;	//�̸�

			string type;
			cin >> type;	//����

			int check = 0;	//�׳� Ȯ�ο�

			for (int k = 0; k < index; k++) {
				if (type == types[k]) {	//�Է¹��� �� types�� ���� ���
					cntType[k]++;	//�ش� type�� ����++
					check = 1;
					break;
				}
			}
			if (check == 0) {	//�Է¹��� �� types�� ���� ���
				types[index] = type;	//types�� �߰�����
				cntType[index] += 1;	//cntType�� �� ���� �־���
				index++;
			}
		}

		int res = 1;
		for (int i = 0; i < index; i++)
			res *= (cntType[i] + 1);

		cout << res - 1 << "\n";

	}


	return 0;
}