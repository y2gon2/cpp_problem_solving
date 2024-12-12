#include <iostream>
#include <queue>

using namespace std;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	int dasom = 0;
	priority_queue<int> pq;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;

		if (i == 0) {
			dasom = num;
		}
		else {
			pq.push(num);
		}
	}

	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}

	int count = 0;
	int top_vote = pq.top();

	while (top_vote >= dasom) {
		//cout << "dasom : " << dasom << ", top vote : " << top_vote << '\n';
		pq.pop();
		pq.push(--top_vote);
		count++;
		dasom++;

		top_vote = pq.top();
	}

	cout << count << '\n';
	return 0;
}