#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/1965
// 상자넣기

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> boxes(n, 0);
	vector<int> acc(n, 1);

	int result = 1;

	for (int& b: boxes) {
		cin >> b;
	}

	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (boxes[i] < boxes[j]) {
				acc[j] = max(acc[j], acc[i] + 1);
				result = max(result, acc[j]);
			}
		}
	}

	cout << result << '\n';
	return 0;
}