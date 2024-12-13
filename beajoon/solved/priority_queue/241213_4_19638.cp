#include <iostream>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/19638
// 19638 센티와 마법의 뿅망치

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, centi, hammering;
	cin >> n >> centi >> hammering;

	priority_queue<int, vector<int>, less<int>> giants;

	for (int i = 0; i < n; ++i) {
		int g;
		cin >> g;
		giants.push(g);
	}

	int count = 0;

	while (count < hammering) {
		int giant = giants.top();

		if (centi > giant) {
			break;
		}

		giants.pop();
		(giant == 1)? giant: giant /= 2;
		giants.push(giant);
		count++;
	}

	if (centi > giants.top()) {
		cout << "YES" << '\n';
		cout << count << '\n';
	}
	else {
		cout << "NO" << '\n';
		cout << giants.top() << '\n';
	}
	return 0;
}