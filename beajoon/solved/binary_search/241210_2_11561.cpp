#include <iostream>

using namespace std;

// https://www.acmicpc.net/problem/11561
// 11561 징검다리


void binary_search() {
	unsigned long long num;
	cin >> num;

	unsigned long long left = 1;
	unsigned long long right = num;

	while (left <= right) {
		unsigned long long mid = (left + right) / 2;
		if (mid * (mid + 1) / 2 <= num) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	
	cout << left - 1 << '\n';
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cout.tie(NULL);
	cout.sync_with_stdio(false);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		binary_search();
	}

	return 0;
}