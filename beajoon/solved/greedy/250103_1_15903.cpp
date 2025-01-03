#include <iostream>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/15903
// 카드 합체 놀이

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n; ++i) {
		long long num;
		cin >> num;

		pq.push(num);
	}

	for (int i = 0; i < m; ++i) {
		long long v1 = pq.top();
		pq.pop();

		long long v2 = pq.top();
		pq.pop();

		pq.push(v1 + v2);
		pq.push(v1 + v2);
	}

	long long result = 0;
	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}
	cout << result << '\n';
	return 0;
}