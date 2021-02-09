#pragma warning(disable:4996)
#include <iostream>
#include <stack>
using namespace std;

int main() {

	int n;
	cin >> n;

	while (n) {
		long long* arr = new long long[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];	// ���̶� index
		long long area = 0;	// ���� ���� ���� ����

		stack<int> s;	// index ���� stack

		for (int i = 0; i < n; i++) {
			while (!s.empty() && arr[i] < arr[s.top()]) {
				long long temp = arr[s.top()];
				s.pop();
				long long width;
				if (s.empty()) {
					width = i;
				}
				else {
					width = i - s.top() - 1;
				}
				if (area < width * temp)
					area = width * temp;
			}
			s.push(i);
		}

		while (!s.empty()) {
			long long temp = arr[s.top()];
			s.pop();
			long long width;
			if (s.empty())
				width = n;
			else
				width = n- s.top() - 1;
			if (temp * width > area)
				area = temp * width;
		}
		cout << area << "\n";
		cin >> n;
	}



	return 0;
}