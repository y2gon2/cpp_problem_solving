#include <iostream>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/16173
// 16173 점프왕 쩰리 (Small)

void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j, int n) {
	
	// 영역을 벗어났거나 이미 방문했다면 그대로 return
	if (i < 0 || i >= n || j < 0 || j >= n) {
		return;
	}
	
	// 기존에 방문한 곳이면 바로 return
	if (visited[i][j]) {
		return;
	}

	visited[i][j] = true;

	// 목적지 도착했다면 방문 표시만 하고 바로 return
	if (matrix[i][j] == -1) {
		return;
	}
	
	dfs(matrix, visited, i + matrix[i][j], j, n);
	dfs(matrix, visited, i, j + matrix[i][j], n);	
    return;
}

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

	dfs(matrix, visited, 0, 0, n);
	
	(visited[n - 1][n - 1]) ? cout << "HaruHaru" << '\n' : cout << "Hing" << '\n';
	return 0;
}