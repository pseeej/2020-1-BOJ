#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int k;
	cin >> k;

	while (k != 0) {

		vector<int> v;	// �迭 S ���� vector
		for (int i = 0; i < k; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}

		vector<int> temp;	// ����� �� ����� üũ�� vector
		for (int i = 0; i < 6; i++)	// ��� �� ������ŭ
			temp.push_back(1);
		for (int i = 0; i < k - 6; i++)	// �Է¹��� ����-�� ����
			temp.push_back(0);

		//sort(temp.begin(), temp.end());

		do {
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i] == 1)
					cout << v[i] << " ";
			}
			cout << "\n";
		} while (prev_permutation(temp.begin(), temp.end()));

		cout << "\n";

		cin >> k;

	}

	return 0;
}