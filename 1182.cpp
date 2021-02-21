#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int arr[20] = { 0, };
int N, S;
int cnt = 0;

void dfs(int sum, int input) {
	if (sum == S && input != 0)
		cnt++;

	if (input == N)	// ������ �̷� ���̸� for�� ������ ����
		return;

	for (int i = input; i < N; i++)
		dfs(sum + arr[i], i + 1);
}


int main() {

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dfs(0, 0);

	cout << cnt;

	return 0;
}