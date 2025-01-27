#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/2548
// 대표 자연수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> nums(n);

	for (int& num : nums) {
		cin >> num;
	}

	vector<int> values(10001, 0);

	for (int i = 1; i < 10001; ++i) {
		for (int num : nums) {
			values[i] += abs(i - num);
		}
	}
	
	int result = 200000001;
	int ans = 0;
	for (int i = 1; i < 10001; ++i) {
		if (result > values[i]) {
			result = values[i];
			ans = i;
		}
	}

	cout << ans << '\n';
	return 0;
}