#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/12865
// 평범한 배낭 (Knapsack Problem)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> knapsack(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; ++i) {
		int w, v;
		cin >> w >> v;

		for (int remain = 0; remain <= k; ++remain) {
			knapsack[i][remain] = max(knapsack[i][remain], knapsack[i - 1][remain]);

			if (remain - w >= 0) {
				knapsack[i][remain] = max(knapsack[i][remain], knapsack[i - 1][remain - w] + v);
			}
		}
	}

	int result = 0;
	for (auto row : knapsack) {
		for (int value : row) {
			result = max(result, value);
		}
	}

	cout << result << '\n';
	return 0;
}