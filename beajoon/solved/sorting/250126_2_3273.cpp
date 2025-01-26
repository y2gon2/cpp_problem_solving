#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/3273
// 두 수의 합

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n;
	vector<int> nums(n);

	for (int& num : nums) {
		cin >> num;
	}

	cin >> x;

	sort(nums.begin(), nums.end());

	int left = 0;
	int right = n - 1;

	int result = 0;
	while (left < right) {
		int added = nums[left] + nums[right];

		if (added == x) {
			++result;
			--right;
			++left;
		}
		else if (added > x) {
			--right;
		} 
		else {
			++left;
		}
	}

	cout << result << '\n';
	return 0;
}