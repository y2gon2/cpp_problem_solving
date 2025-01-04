#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/11722
// 가장 긴 감소하는 부분 수열

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> nums(n);

	for (int& num : nums) {
		cin >> num;
	}

	vector<int> len_memo(n, 1);

	for (int i = n - 2; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			if (nums[i] > nums[j]) {
				len_memo[i] = max(len_memo[i], len_memo[j] + 1);
			}
		}
	}

	int result = 1;

	for (int i = 0; i < n; ++i) {
		result = max(result, len_memo[i]);
	}

	cout << result << '\n';
	return 0;
}