#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int> maxpq;
	priority_queue<int, vector<int>, greater<int>> minpq;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		// maxpq�� size�� min�� size���� ���ų� Ŀ����
		if (maxpq.size() == minpq.size())
			maxpq.push(temp);
		else    // ���� �����ֱ� ����
			minpq.push(temp);

		// min�� �ִ� ���� max���� �� ������
		// ���� top�� �ִ� �� swap��
		if (!minpq.empty() && !maxpq.empty() && minpq.top() < maxpq.top()) {
			int a = maxpq.top();
			int b = minpq.top();

			maxpq.pop();
			minpq.pop();
			maxpq.push(b);
			minpq.push(a);
		}

		// �̰� ������� ��
		cout << maxpq.top() << "\n";
	}



	return 0;
}