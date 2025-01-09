#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Dynamic Programming
// https://www.acmicpc.net/problem/1699
// 제곱수의 합
// https://chatgpt.com/c/677c82e3-25fc-8000-94af-d6eef63b0707

void dp(vector<int>& nums, int i) {
//	nums[i] = 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> nums(n + 1, 0);
	nums[1] = 1;

	for (int i = 2; i <= n; ++i) {
		dp(nums, i);
	}

	cout << nums[n] << '\n';
	return 0;
}