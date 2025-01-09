#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/11060
// 점프 점프

const int LIMIT = 1001;

void dp(const vector<int>& maze, vector<int>& steps, int cur, int n) {
	for (int i = 1; i <= maze[cur]; ++i) {
		int next = cur + i;

		if (next < n) {
			if (steps[next] == -1 || steps[next] > steps[cur] + 1) {
				steps[next] = steps[cur] + 1;
				dp(maze, steps, next, n);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> maze(n, 0);
	vector<int> steps(n, -1);
	steps[0] = 0;

	for (int i = 0; i < n; ++i) {
		cin >> maze[i];
	}

	dp(maze, steps, 0, n);

	cout << steps[n - 1] << '\n';
	return 0;
}