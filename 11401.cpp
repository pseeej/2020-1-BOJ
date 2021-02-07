#pragma warning(disable:4996)
#include <iostream>
using namespace std;

long long mod = 1000000007;

long long fac[4000010];
long long inv[4000010];

// �丣�� �������� �̿��� nCr ������ ���ϱ�
// ���丮�� %MOD ���� ���� ��ó���� ��
// �� ���丮���� modular inverse�� ����

// nCr = n!/k!(n-k)!�̹Ƿ� 1/k!(n-k)!�� k!(n-k)!^MOD-2�� ġȯ ����

long long fermat(long long x, long long y) {
	long long ret = 1;
	while (y > 0) {
		if (y % 2) {
			ret *= x;
			ret %= mod;
		}
		x *= x;
		x %= mod;
		y /= 2;
	}
	return ret;
}

int main() {

	long long int n, k;
	cin >> n >> k;

	fac[1] = 1;
	for (int i = 2; i <= n; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
	}

	inv[n] = fermat(fac[n], mod - 2);

	for (long long i = n - 1; i >= 1; i--) {
		inv[i] = (inv[i + 1] * (i + 1)) % mod;
	}

	long long first = fac[n] * inv[n - k] % mod;

	if (n == k || k == 0)
		cout << '1';
	else
		cout << first * inv[k] % mod;


	return 0;
}