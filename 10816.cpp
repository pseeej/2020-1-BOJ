#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);	// �ð� �ʰ� ó�� ����

	int N;
	cin >> N;

	vector<int> v(N);	// v�� �ִ� ũ�� ����
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		// num���� ū ���ڰ� ó������ ������ ��ġ - num �̻��� ���ڰ� ó������ ������ ��ġ
		cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << " ";
	}


	return 0;
}