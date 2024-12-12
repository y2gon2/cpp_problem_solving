#include <iostream>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/4158
// 4158 CD

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cout.tie(NULL);
	cout.sync_with_stdio(false);

	while (true) {
		int result = 0;
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}

		vector<int> cdList(n, 0);

		for (int& c : cdList) {
			cin >> c;
		}

		for (int i = 0; i < m; ++i) {
			int x;
			cin >> x;

			int left = 0;
			int right = n - 1;

			while (left <= right) {
				int mid = (left + right) / 2;
				if (cdList[mid] == x) {
					result++;
					break;
				}
				else if (cdList[mid] < x) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}

		cout << result << '\n';
	}

	return 0;
}