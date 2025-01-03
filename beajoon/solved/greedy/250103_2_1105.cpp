#include <iostream>

using namespace std;

// https://www.acmicpc.net/problem/1105
// 팔

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned int result = 0;
	unsigned int l, r;
	cin >> l >> r;

	unsigned int diff = r - l;

	while (l != 0) {
		unsigned int l1 = l % 10;
		unsigned int r1 = r % 10;

		//cout << "diff :" << diff << '\n';
		if(l1 == 8 && r1 == 8 && diff == 0) ++result;

		l /= 10;
		r /= 10;
		diff /= 10;
	}

	cout << result << '\n';
	return 0;
}