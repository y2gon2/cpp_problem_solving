// https://www.acmicpc.net/problem/1940
// 1940 주몽

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int result = 0;

	int n, m;
	cin >> n;
	cin >> m;
	cin.ignore();

	vector<int> nums(n, 0);

	string input;
	getline(cin, input);

	stringstream ss(input);
	int num;

	for (auto it = nums.begin(); it != nums.end() ; ++it ) {
		ss >> num;
		*it = num;
	}

	sort(nums.begin(), nums.end());

	int small = 0;
	int large = n - 1;

	while (small < large) {
		if (nums[small] + nums[large] == m) {
			result++;;
			small++;
			large--;
		} 
		else if (nums[small] + nums[large] < m) {
			small++;
		}
		else {
			large--;
		}
	}

	cout << result << endl;

	return 0;
}