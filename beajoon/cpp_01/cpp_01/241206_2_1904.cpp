// https://www.acmicpc.net/problem/1904
// 1904 01≈∏¿œ

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> memo(n + 1, 0);
	memo[1] = 1;
	memo[2] = 2;

	for (int i = 3; i < n + 1; i++) {
		memo[i] = (memo[i - 1] + memo[i - 2]) % 15746;
	}

	cout << memo[n] << endl;

	return 0;
}