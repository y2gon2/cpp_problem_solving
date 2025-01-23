#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

// https://www.acmicpc.net/problem/1535
// 안녕
// 배낭 채우기 문제 (Knapsack Problem) (https://gsmesie692.tistory.com/113)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();

	vector<vector<int>> dp(n + 1, vector<int>(100, 0));
	
	string s_cost, s_joy;

	getline(cin, s_cost);
	stringstream sc(s_cost);

	getline(cin, s_joy);
	stringstream sj(s_joy);

	for (int i = 1; i < n + 1; ++i) {
		// 현재 사람에게 인사를 할 때 필요한 체력과 얻는 기쁨
		int cost, joy;

		sc >> cost;
		sj >> joy;

		for (int hp = 0; hp < 100; ++hp) {
			// 인사를 하지 않는 경우
			dp[i][hp] = max(dp[i][hp], dp[i - 1][hp]);

			// 인사를 하는 경우
			if (hp - cost >= 0) {
				dp[i][hp] = max(dp[i][hp], dp[i - 1][hp - cost] + joy);
			}
		}
	}

	int result = 0;
	for (auto row: dp) {
		for (int total_joy : row) {
			result = max(result, total_joy);
		}
	}

	cout << result << '\n';
	return 0;
}
