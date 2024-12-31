#include <iostream>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/2847
// 게임을 만든 동준이

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> nums;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	int result = 0;
	int prev = nums[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		if (nums[i] >= prev) {
			result += nums[i] - prev + 1;
			--prev;
		}
		else {
			prev = nums[i];
		}
	}

	cout << result << '\n';
	return 0;
}