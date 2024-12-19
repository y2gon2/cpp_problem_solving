#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef unsigned long long ull;

// https://www.acmicpc.net/problem/1590
// 1590 캠프가는 영식

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	ull result = ULLONG_MAX;
	int n;
	ull t;
	cin >> n >> t;
	
	for (int i = 0; i < n; ++i) {
		ull s, l, c;
		cin >> s >> l >> c;

		ull limit = s + (l * (c - 1));

		if (t > limit) {
			//cout << "limit" << limit << '\n';
			continue;
		}

		int left = 0;
		int right = c;

		while (left <= right) {
			ull mid = (left + right) / 2;
			ull waitingTime = s + l * mid;
			
			if (waitingTime >= t) {
				result = min(result, waitingTime - t);
				//cout << mid << ", " << waitingTime << ", " << result << '\n';
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}

	if (result == ULLONG_MAX) {
		cout << -1 << '\n';
	}
	else {
		cout << result << '\n';
	}

	return 0;
}