#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/16493
// 최대 페이지 수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> book(n + 1, 0);

	for (int i = 1; i <= m; ++i) {
		int duration, pages;
		cin >> duration >> pages;

		for (int remain = n; remain >= duration; --remain) {
			book[remain] = max(book[remain], book[remain - duration] + pages);
		}
	}

	cout << book[n] << '\n';
	return 0;
}