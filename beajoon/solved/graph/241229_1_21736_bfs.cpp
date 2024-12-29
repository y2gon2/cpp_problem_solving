#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// https://www.acmicpc.net/problem/21736
// 헌내기는 친구가 필요해

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> directions = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

	int n, m;
	cin >> n >> m;
	cin.ignore();

	vector<vector<int>> campus(n);
	
	vector<bool> row(m, false);
	vector<vector<bool>> visited(n, row);

	pair<int, int> start = {0, 0};

	for (int i = 0; i < n; ++i) {
		string input;
		getline(cin, input);

		for (int j = 0; j < m; ++j) {
			if (input[j] == 'O') {
				campus[i].push_back(0);
			}
			else if (input[j] == 'I') {
				campus[i].push_back(0);
				start = { i, j };
			}
			else if (input[j] == 'P') {
				campus[i].push_back(1);
			}
			else {
				campus[i].push_back(-1);
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = true;

	int result = 0;

	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();

		if (campus[current.first][current.second] == 1) {
			++result;
		}

		//cout << "i: " << current.first << ", j: " << current.second << ", result:" << result << '\n';

		for (auto d : directions) {
			int dy = current.first + d.first;
			int dx = current.second + d.second;

			if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
				if (!visited[dy][dx] && campus[dy][dx] != -1) {
					q.push({ dy, dx });
					visited[dy][dx] = true;
				}
			}
		}
	}

	if (result == 0) cout << "TT" << '\n';
	else cout << result << '\n';

	return 0;
}