#include <iostream>
#include <vector>

using namespace std;

// 2차원 배열의 합
// https://www.acmicpc.net/problem/2167

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
	
	//    1 |   |
	//    - | + |  -> 1번 영역이 2번 더해지므로 1번 영역을 다시 뺌
	//  ---- ---
	//    + | + | 
	//  ---- ---
	//  누적합 행렬 작성시
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int num;
			cin >> num;

			matrix[i][j] += (num + matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1]);
		}
	}

	int k;
	cin >> k;

	// 누적합 행렬에서 부분합을 구할 시
	//      |     |
	//    + |   - |  -> 1번 영역이 2번 제거되므로 1번 영역을 다시 더함
	//  ----- ----
	//    - |(i,j)|
	//  ----------
	//      |          |
	//      |          |
	//      |   +(x,y) | 
	//  ---- ----------
	for (int a = 0; a < k; ++a) {
		int result = 0;
		int i, j, x, y;
		cin >> i >> j >> x >> y;

		int partial_acc = matrix[x][y] - matrix[i - 1][y] - matrix[x][j - 1] + matrix[i - 1][j - 1];
		cout << partial_acc << '\n';
	}

	return 0;
}