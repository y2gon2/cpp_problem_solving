#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/10451
// 10451 순열 사이클

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	int test;
	cin >> test;

	for (int i = 0; i < test; ++i) {
		int result = 0;

		int n;
		cin >> n;

		vector<int> numbers(n + 1);
		vector<bool> visited(n + 1, false);

		for (int j = 1; j <= n; ++j) {
			int num;
			cin >> num;
			numbers[j] = num;
		}

		for (int j = 1; j <= n; ++j) {
			if (!visited[j]) {
				queue<int> q;
				q.push(numbers[j]);
				visited[j] = true;

				while (!q.empty()) {
					int next = q.front();
					q.pop();

					if (!visited[next]) {
						q.push(numbers[next]);
						visited[next] = true;
					}
				}
				++result;
			}
		}
		cout << result << '\n';
	}
	return 0;
}