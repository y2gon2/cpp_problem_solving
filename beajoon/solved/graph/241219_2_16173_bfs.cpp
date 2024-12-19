#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/16173
// 16173 점프왕 쩰리 (Small)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	vector<vector<int>> matrix(n);
	vector<vector<bool>> visited(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int num;
			cin >> num;
			matrix[i].push_back(num);
			visited[i].push_back(false);
		}
	}

	vector<vector<int>> move = { {1, 0}, {0, 1} };
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		auto current = q.front();
		q.pop();

		int jump = matrix[current.first][current.second];
		
		for (const auto p : move) {
			int dx = current.first + jump * p[0];
			int dy = current.second + jump * p[1];

			if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
				if (!visited[dx][dy]) {
					visited[dx][dy] = true;

					if (matrix[dx][dy] != -1) {
						q.push({ dx, dy });
					}
				}
			}
		}
	}
	
	(visited[n - 1][n - 1]) ? cout << "HaruHaru" << '\n' : cout << "Hing" << '\n';
	return 0;
}