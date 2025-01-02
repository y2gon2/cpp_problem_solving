#include <iostream>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/20115
// 에너지 드링크

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int mx;
	cin >> mx;

	float rest_total = 0.0;

	for (int i = 1; i < n; ++i) {
		int num;
		cin >> num;

		if (mx < num) {
			rest_total += static_cast<float>(mx);
			mx = num;
		}
		else {
			rest_total += static_cast<float>(num);
		}
	}

	cout << static_cast<float>(mx) + (rest_total / 2) << '\n';
	return 0;
}