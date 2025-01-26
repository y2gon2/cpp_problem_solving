#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/22115
// 창영이와 커피

const int LIMIT = 1001;

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/22115
// 창영이와 커피

const int LIMIT = 1001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> dp(k + 1, LIMIT);

	// 최초 dp 설정 dp[0] = 0  dp[나머지] = LIMIT
	// -> pq 에서 하나씩 꺼냈을 때, dp[c] = min(LIMIT, dp[0] + 1) => 1 로 되도록 설정
	dp[0] = 0;

	// 1 번씩 마시는건 이미 반영됨.
	// 이후 n 개의 커피를 마시는 경우를 반영
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;

		// 작은 값부터 돌면 안됨!! 
		// -> 현 단계의 값변화에 영향을 받아서 뒤의 큰값들이 모두 값을 가지게 됨.
		for (int j = k; j >= c ; --j) {
			dp[j] = min(dp[j], dp[j - c] + 1);
		}

		//for (int a = 1; a < k + 1; ++a) {
		//	cout << dp[a] << ' ';
		//}
		//cout << '\n';
	}

	if (dp[k] == LIMIT) {
		cout << -1 << '\n';
	}
	else {
		cout << dp[k] << '\n';
	}

	return 0;
}


/*
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> dp(k + 1, LIMIT);
	priority_queue<int, vector<int>, less<int>> pq;

	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		pq.push(c);
	}

	// 최초 dp 설정 dp[0] = 0  dp[나머지] = LIMIT
	// -> pq 에서 하나씩 꺼냈을 때, dp[c] = min(LIMIT, dp[0] + 1) => 1 로 되도록 설정
	dp[0] = 0;

	// 1 번씩 마시는건 이미 반영됨.
	// 이후 n 개의 커피를 마시는 경우를 반영
	while (!pq.empty()) {
		int c = pq.top();
		pq.pop();

		// 작은 값부터 돌면 안됨!! 
		// -> 현 단계의 값변화에 영향을 받아서 뒤의 큰값들이 모두 값을 가지게 됨.
		for (int j = k; j >= c ; --j) {
			dp[j] = min(dp[j], dp[j - c] + 1);
		}

		//for (int a = 1; a < k + 1; ++a) {
		//	cout << dp[a] << ' ';
		//}
		//cout << '\n';
	}

	if (dp[k] == LIMIT) {
		cout << -1 << '\n';
	}
	else {
		cout << dp[k] << '\n';
	}

	return 0;
}
*/
