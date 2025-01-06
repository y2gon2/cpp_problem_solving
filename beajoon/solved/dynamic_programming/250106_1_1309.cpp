#include <iostream>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/1309
// 동물원

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// 3 * n -> 각 열에 대해 양쪽다 X, 왼쪽만, 오른쪽만 넣는 경우의 수를 입력하기 위해
	vector<vector<int>> cages(n, vector<int>(3, 0));

	// 최초 칸에 넣은 경우 : 양쪽다 X, 왼쪽만, 오른쪽만 각각 1 개의 경우 존재
	for (int i = 0; i < 3; ++i) {
		cages[0][i] = 1;
	}

	if (n > 1) {
		for (int i = 1; i < n; ++i) {
			// 다음 칸을 모두 비운 경우는 앞의 모든 경우의 수를 가져올 수 있음
			cages[i][0] = (cages[i - 1][0] + cages[i - 1][1] + cages[i - 1][2]) % 9901;
			// 왼쪽칸을 채우는 경우는 이전 단계 왼쪽칸을 채운 경우는 가져올 수 없음
			cages[i][1] = (cages[i - 1][0] + cages[i - 1][2]) % 9901;
			// 오른쪽칸을 채우는 경우 이전 단계 오른쪽칸을 채운 경우는 가져올 수 없음
			cages[i][2] = (cages[i - 1][0] + cages[i - 1][1]) % 9901;
		}
	}

	int result = (cages[n - 1][0] + cages[n - 1][1] + cages[n - 1][2]) % 9901;
	cout << result << '\n';
	return 0;
}