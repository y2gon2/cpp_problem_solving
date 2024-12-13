#include <iostream>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/14235
// 14235 크리스마스 선물

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cout.tie(NULL);
	cout.sync_with_stdio(false);


	int n;
	cin >> n;

	priority_queue<int> pq;

	for (int i = 0; i < n; ++i) {		
		int p;
		cin >> p;
		
		if (p == 0) {
			if (pq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			for (int j = 0; j < p; ++j) {
				int gift;
				cin >> gift;
				pq.push(gift);
			}
		}
	}
	return 0;
}