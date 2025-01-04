#include <iostream>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/2212
// 센서

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	priority_queue<int, vector<int>, greater<int>> sensors;
	priority_queue<int, vector<int>, less<int>> distances;
		
	for (int i = 0; i < n; ++i) {
		int s;
		cin >> s;
		sensors.push(s);
	}

	int prev = sensors.top();
	sensors.pop();

	while (!sensors.empty()) {
		int cur = sensors.top();
		sensors.pop();

		int d = cur - prev;
		prev = cur;

		if (d > 0) distances.push(d);
	}

	int result = 0;
	int len = distances.size();
	//cout << "k : " << k << '\n';

	for (int i = 1; i <= len; ++i) {
		//cout << distances.top() << '\n';
		if (i > k - 1) {
			// cout << "d : " << distances.top() << '\n';
			result += distances.top();
		}
		distances.pop();
	}

	cout << result << '\n';
	return 0;
}