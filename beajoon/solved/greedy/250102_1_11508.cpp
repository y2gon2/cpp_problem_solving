#include <iostream>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/11508
// 2+1 세일

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long result = 0;
	int n;
	cin >> n;

	priority_queue<int, vector<int>, less<int>> pq;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;

		pq.push(num);
	}

	for (int i = 0; i < n; ++i) {
		int value = pq.top();
		pq.pop();

		if (i % 3 < 2) result += static_cast<long long>(value);
	}

	cout << result << '\n';

	return 0;
}