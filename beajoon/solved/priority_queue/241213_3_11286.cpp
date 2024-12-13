#include <iostream>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/11286
// 11286 절댓값 힙

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	priority_queue<long long, vector<long long>, greater<long long>> pqPlus;
	priority_queue<long long, vector<long long>, less<long long>> pqMinus;

	long long result;

	for (int i = 0; i < n; ++i) {
		long long num;
		cin >> num;

		if (num == 0) {
			if (pqPlus.empty() && pqMinus.empty()) {
				result = 0;
			}
			else if (!pqPlus.empty() && pqMinus.empty()) {
				result = pqPlus.top();
				pqPlus.pop();
			}
			else if (pqPlus.empty() && !pqMinus.empty()) {
				result = pqMinus.top();
				pqMinus.pop();
			}
			else {
				long long plus = pqPlus.top();
				long long minus = pqMinus.top();

				if (abs(minus) <= abs(plus)) {
					result = minus;
					pqMinus.pop();
				}
				else {
					result = plus;
					pqPlus.pop();
				}
			}
			cout << result << '\n';
		}
		else {
			(num > 0) ? pqPlus.push(num) : pqMinus.push(num);
		}
	}
	return 0;
}