#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// https://www.acmicpc.net/problem/24479
// 24479 알고리즘 수업 - 깊이 우선 탐색 1

using namespace std;

void dfs(
	vector<priority_queue<int, vector<int>, greater<int>>>& nodes, 
	vector<bool>& visited, 
	vector<int>& result,
	int num,
	int& count
) {
	if (visited[num]) {
		return;
	}
	visited[num] = true;
	result[num] = count;

	while (!nodes[num].empty()) {
		int next = nodes[num].top();
		nodes[num].pop();

		if (!visited[next]) {
			count++;
			dfs(nodes, visited, result, next, count);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m, s;
	cin >> n >> m >> s;

	vector<priority_queue<int, vector<int>, greater<int>>> nodes(n + 1);
	vector<bool> visited(n + 1, false);
	vector<int> result(n + 1, 0);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		nodes[a].push(b);
		nodes[b].push(a);
	}

	int count = 1;
	dfs(nodes, visited, result, s, count);

	for (int i = 1; i <= n; ++i) {
		cout << result[i] << '\n';
	}

	return 0;
}