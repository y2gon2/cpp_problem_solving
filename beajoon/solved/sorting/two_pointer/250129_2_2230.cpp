#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/2230
// 수 고르기

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> nums(n);
	for (int& num : nums) {
		cin >> num;
	}

	sort(nums.begin(), nums.end());

	int result = 2000000001;

	int i = 0;
	int j = 1;
	while (j < n) {
		int diff = nums[j] - nums[i];

		if (diff >= m) {
			result = min(result, diff);
			++i;
		}
		else {
			++j;
		}
		if (j < i) {
			j = i;
		}
	}

	cout << result << '\n';
	return 0;
}