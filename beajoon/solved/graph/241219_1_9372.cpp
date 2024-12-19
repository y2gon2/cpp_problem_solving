#include <iostream>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/9372
// 9372 상근이의 여행
// DFS

int dfs(vector<vector<int>>& countries, vector<bool>& visited, int a, int cnt, int n) {
	visited[a] = true;

	for (int c : countries[a]) {
		// cout << cnt << '\n';
		if (!visited[c]) {
			cnt++;
			cnt = dfs(countries, visited, c, cnt, n);
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;

	for (int t = 0; t < test; ++t) {
		int n, m;
		int cnt = 0;
		cin >> n >> m;

		vector<vector<int>> countries(n + 1);
		vector<bool> visited(n + 1, false);

		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;

			countries[a].push_back(b);
			countries[b].push_back(a);
		}
		
		cnt = dfs(countries, visited, 1, 0, n);

		cout << cnt << '\n';
	}

	return 0;
}