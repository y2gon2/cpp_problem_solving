#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/2012
// 등수 매기기


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		pq.push(num);
	}

	long long result = 0;

	for (int i = 1; i <= n; ++i) {
		int person = pq.top();
		pq.pop();
		
		result += static_cast<long long>(abs(i - person));
	}

	cout << result << '\n';
	return 0;
}