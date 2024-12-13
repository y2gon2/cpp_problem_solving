#include <iostream>
#include <queue>

using namespace std;

// https://www.acmicpc.net/problem/23757
// 23757 아이들과 선물 상자

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	priority_queue<int> giftQ;

	for (int i = 0; i < n; ++i) {
		int gift;
		cin >> gift;
		giftQ.push(gift);
	}

	int result = 1;
	for (int i = 0; i < m; ++i) {
		int child;
		cin >> child;

		int topGift = giftQ.top();
		giftQ.pop();

		if (child > topGift) {
			result = 0;
			break;
		}
		else {
			giftQ.push(topGift - child);
		}
	}

	cout << result << '\n';

	return 0;
}