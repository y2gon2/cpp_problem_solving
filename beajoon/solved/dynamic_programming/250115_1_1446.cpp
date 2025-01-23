#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/1446
// 지름길

const int LIMIT = 10001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d;
	cin >> n >> d;

	vector<int> distances(d + 1, LIMIT);
	vector<vector<pair<int, int>>> shortcuts(d + 1);

	for (int i = 0; i < n; ++i) {
		int from, to, dis;
		cin >> from >> to >> dis;

		shortcuts[from].push_back({ to, dis });
	}

	distances[0] = 0;

	for (int i = 0; i < d; ++i) {
		distances[i + 1] = min(distances[i + 1], distances[i] + 1);

		if (!shortcuts[i].empty()) {
			for (auto s : shortcuts[i]) {
				if (s.first <= d) {
					distances[s.first] = min(distances[s.first], distances[i] + s.second);
				}
			}
		}
	}

	cout << distances[d] << '\n';
	return 0;
}