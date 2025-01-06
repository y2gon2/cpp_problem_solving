#include <iostream>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/1890
// 점프

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<long long>> steps(n, vector<long long>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int s;
			cin >> s;
			board[i][j] = s;
		}
	}

	steps[0][0] = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

			// 목표점에 도착했거나, 해당 칸에서 이동할 수 없다면  skip
			if ((i == n - 1 && j == n - 1) || board[i][j] == 0) {
				continue;
			}

			int jump = board[i][j];

			// 아래쪽으로 이동 가능하다면 경우의 수 누적
			if (i + jump < n) {
				steps[i + jump][j] += steps[i][j];
			}

			// 오른쪽으로 이동 가능하다면 경우의 수 누적
			if (j + jump < n) {
				steps[i][j + jump] += steps[i][j];
			}
		}
	}

	cout << steps[n - 1][n - 1] << '\n';

	return 0;
}


