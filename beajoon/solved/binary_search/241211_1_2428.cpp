#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/2428
// 2428 표절

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> files(n, 0);

	for (int &f: files) {
		cin >> f;
	}

	sort(files.begin(), files.end());

	long long count = 0;

	for (int i = 0; i < n; ++i) {
		int limit = (int)((double)files[i] / 0.9);

		int left = i + 1;
		int right = n - 1;
		int upperIdx = i;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (files[mid] <= limit) {
				upperIdx = mid;
				left = mid + 1;
			} 
			else {
				right = mid - 1;
			}
		}

		if (upperIdx > i) {
			count += (upperIdx - i);
		}
	}

	cout << count << '\n';
	return 0;
}