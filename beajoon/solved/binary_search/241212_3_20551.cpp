#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/20551
// 20551 Sort 마스터 배지훈의 후계자

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cout.tie(NULL);
	cout.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> numbers(n, 0);

	for (int& num : numbers) {
		cin >> num;
	}

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < m; ++i) {
		int d;
		cin >> d;

		int left = 0;
		int right = n - 1;
		int result = -1;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (numbers[mid] >= d) {
				right = mid - 1;
				if (numbers[mid] == d) result = mid;
			}
			else {
				left = mid + 1;
			}
		}
		cout << result << '\n';
	}

	return 0;
}