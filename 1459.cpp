#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	long long x, y;
	int w, s;
	cin >> x >> y >> w >> s;

	long long mod = (x + y) % 2;
	if (x < y) swap(x, y);	//x�� �� ū ���� ������ ��

	// ����� �� �� ����

	// ���༱���θ� ����
	// �밢�����θ� ����
	// �밢������ �� �� �ִ� ��ŭ ���ٰ� ���༱���� ����

	// �� �� �밢���� /�� \ �� ���� ��� ����.
	// �밢�����θ� ������ x+y�� ¦������ ��

	cout << min((x + y) * w, min((x - mod) * s + mod * w, y * s + (x - y) * w));

	return 0;
}