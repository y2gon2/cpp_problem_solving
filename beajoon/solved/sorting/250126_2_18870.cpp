#include <iostream>
#include <vector>
#include <set>

using namespace std;

// https://www.acmicpc.net/problem/18870
// 좌표 압축

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	set<pair<int, int>> s;
	vector<int> nums(n, 0);

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		s.insert({a, i});
	}
	
	int index = -1;
	int prev = 1000000001;
	for (auto s_element : s) {
		if (prev != s_element.first) {
			++index;
			prev = s_element.first;
		}
		nums[s_element.second] = index;

		//cout << "prev : " << prev << ". first : " << s_element.first << ", index : " << index << '\n';
	}
	
	for (int num : nums) {
		cout << num << ' ';
	}
	cout << '\n';

	return 0;
}