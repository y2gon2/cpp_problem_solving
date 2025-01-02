#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/11497
// 통나무 건너뛰기

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;

		priority_queue<int, vector<int>, less<int>> pq;

		for (int j = 0; j < m; ++j) {
			int l;
			cin >> l;
			pq.push(l);
		}

		int left1, left2, right1, right2;
		int result = 0;

		left2 = pq.top();
		right1 = pq.top();
		pq.pop();

		while (true) {
			if (!pq.empty()) {
				left1 = pq.top();
				pq.pop();
				result = max(result, left2 - left1);
				left2 = left1;
			} 
			else {
				break;
			}

			if (!pq.empty()) {
				right2 = pq.top();
				pq.pop();
				result = max(result, right1 - right2);
				right1 = right2;
			}
			else {
				break;
			}
		}

		result = max(result, abs(left2 - right1));
		cout << result << '\n';
	}
	return 0;
}