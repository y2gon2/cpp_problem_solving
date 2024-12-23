#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/24444
// 24444 알고리즘 수업 - 너비 우선 탐색 1

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;

	vector<vector<int>> nodes(n + 1);
	vector<bool> visited(n + 1, false);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		sort(nodes[i].begin(), nodes[i].end());
	}

	vector<int> result(n + 1, 0);
	int count = 0;

	queue<int> q;
	q.push(r);

	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();

		if (visited[cur_node]) {
			continue;
		}

		++count;
		result[cur_node] = count;
		visited[cur_node] = true;

		for (int next : nodes[cur_node]) {
			q.push(next);
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << result[i] << '\n';
	}

	return 0;
}