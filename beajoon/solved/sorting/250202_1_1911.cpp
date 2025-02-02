#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/1911
// 흙길 보수하기 (sorting, greedy)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < n; ++i) {
		int from, to;
		cin >> from >> to;
		pq.push({ from, to });
	}

	int result = 0;
	int board_end = 0;

	while (!pq.empty()) {
		pair<int, int> dump = pq.top();
		pq.pop();

		//cout << "dump : " << dump.first << '\n';
		for (int i = dump.first; i <= dump.second; ++i) {
			if (board_end <= i && board_end < dump.second) {
				board_end = l + i;
				++result;
				//cout << result << " : " << board_end << '\n';
			}
		}
	}

	cout << result << '\n';
	return 0;
}