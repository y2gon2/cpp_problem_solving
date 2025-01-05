#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/11048
// 이동하기

vector<pair<int, int>> DIR = { {-1, 0}, {-1, -1}, {0, -1} };

void mx(const vector<vector<int>>& maze, vector<vector<int>>& acc, int i, int j) {
	for (auto d : DIR) {
		int dy = i + d.first;
		int dx = j + d.second;

		if (dy >= 0 && dx >= 0) {
			acc[dy][dx] = max(acc[dy][dx], maze[dy][dx] + acc[i][j]);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> row(m, 0);
	vector<vector<int>> maze(n, row);
	vector<vector<int>> acc(n, row);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int num;
			cin >> num;
			maze[i][j] = num;
			acc[i][j] = num;
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			mx(maze, acc, i, j);
		}
	}

	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < m; ++j) {
	//		cout << acc[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	int result = acc[0][0];

	cout << result << '\n';

	return 0;
}