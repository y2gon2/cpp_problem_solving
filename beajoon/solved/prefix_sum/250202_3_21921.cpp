#include <iostream>
#include <vector>

using namespace std;

// 블로그
// https://www.acmicpc.net/problem/21921

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;

	vector<int> days(n + 1, 0);

	int num;
	for (int i = 1; i <= n; ++i) {
		cin >> num;
		days[i] = num + days[i - 1];
	}

	int max_acc = 0;
	int date = 0;
	for (int i = x; i <= n; ++i) {
		int visitors = days[i] - days[i - x];
		if (max_acc == visitors ) {
			++date;
		}
		else if (max_acc < visitors) {
			max_acc = visitors;
			date = 1;
		}
	}

	if (max_acc == 0) {
		cout << "SAD" << '\n';
	}
	else {
		cout << max_acc << '\n';
		cout << date << '\n';
	}
	return 0;
}