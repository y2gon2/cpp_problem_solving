#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

// https://www.acmicpc.net/problem/14940
// 14940 쉬운 최단거리

struct Point {
	int y;
	int x;
	int value;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pair<int, int> directions[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	int n, m;
	cin >> n >> m;
	cin.ignore();

	vector<vector<int>> matrix(n);

	vector<int> basic(m, -1);
	vector<vector<int>> result(n, basic);
	
	vector<bool> v_basic(m, false);
	vector<vector<bool>> visited(n, v_basic);
	
	queue<Point> q;

	for (int i = 0; i < n; ++i) {
		string input;
		getline(cin, input);

		stringstream ss(input);
		for (int j = 0; j < m; ++j) {
			int num;
			ss >> num;

			matrix[i].push_back(num);

			if (num == 2) {
				q.push({ i, j, 0});
				visited[i][j] = true;
				result[i][j] = 0;
			} 
			else if (num == 0) {
				result[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		Point position = q.front();
		// cout << "y: " << position.y << ", x: " << position.x << ", v : " << position.value << '\n';
		q.pop();
				
		for (auto d : directions) {
			int dy = position.y + d.first;
			int dx = position.x + d.second;
			int v = position.value + 1;

			if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
				if (!visited[dy][dx] && matrix[dy][dx] == 1) {
					q.push({ dy, dx, v });
					visited[dy][dx] = true;
					result[dy][dx] = v;
				}
			}
		}
	}

	for (auto m : result) {
		for (int num : m) {
			cout << num << ' ';
		}
		cout << '\n';
	}
	return 0;
}