#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);	// �ð� �ʰ� ó�� ����

	int N;
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		// num���� ū ���ڰ� ó������ ������ ��ġ - num �̻��� ���ڰ� ó������ ������ ��ġ
		if (upper_bound(arr, arr + N, num) - lower_bound(arr, arr + N, num))
			cout << "1 ";
		else
			cout << "0 ";
	}


	return 0;
}