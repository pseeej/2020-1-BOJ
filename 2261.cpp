#pragma warning(disable:4996)
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, int>> v;
map<pair<int, int>, int> m;

typedef long long ll;

ll getDist(pair<int, int> a, pair<int, int> b) {
	int x1 = a.first;
	int y1 = a.second;
	int x2 = b.first;
	int y2 = b.second;

	return pow((x1 - x2), 2) + pow((y1 - y2), 2);
}

int main() {

	int max = 100000;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	
	// x�� ���� ���� x�� �� ���̸����� �ִ밪 �ĺ����� ���� ���� ���� ����
	sort(v.begin(), v.end());

	// map�� �����ִ� ���� �߿��� y������ lower_bound, upper_bound �ϱ� ����
	// ù ��° ���� �� ��° �� ������ �Ÿ��� �������� ����.
	m[{v[0].second, v[0].first}] = 0;
	m[{v[1].second, v[1].first}] = 0;
	ll ans = getDist(v[0], v[1]);

	int pos = 0;
	for (int i = 2; i < n; i++) {
		while (pos < i) {
			// x�ణ�� �Ÿ� ����
			int dx = v[i].first - v[pos].first;

			// pos�� i��° �� x�� ������ �Ÿ��� �� ������
			// pos���� ���� ���� ������ ���� �� �ʿ�� �� �� Ȯ�� ����
			if (dx * dx <= ans)
				break;

			// pos�� i��° �� x�� ������ �Ÿ��� �� ũ��
			// pos�� �� �̻� ��� �Ұ�.
			m.erase({ v[pos].second, v[pos].first });
			pos++;
		}

		// ���� �Ÿ� ��� ���� sqrt
		ll dis = sqrt(ans);

		// map�� ���� �ִ� ���� �߿��� ���� ans���� �۾��� �� �ִ� �ĺ� ���� ã�� ���� left, right ����
		// �� �� auto�� ������ �ʱ�ȭ �Ŀ��� ������ �߷еǴ� ���� ���� ����.
		auto left = m.lower_bound({ v[i].second - dis, -max });
		auto right = m.upper_bound({ v[i].second + dis, max });

		// ans ����.
		for (auto l = left; l != right; l++) {
			ans = min(ans, getDist({ l->first.second, l->first.first }, v[i]));
		}

		// i��° ���� �翬�� �ڿ� Ȯ���� �� ���� �Ŵϱ� �ĺ� ���� ��.
		m[{v[i].second, v[i].first}] = 0;
	}

	cout << ans;

	return 0;
}