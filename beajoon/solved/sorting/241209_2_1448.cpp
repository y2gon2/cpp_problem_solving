#include <iostream>
#include <vector>
#include <algorithm>

// https://www.acmicpc.net/problem/1448
// 1448 삼각형 만들기

using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cout.tie(NULL);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;

	int temp;
	vector<int> strowes(n, 0);

	for (int i = 0; i < n; ++i) {
		cin >> temp;
		strowes[i] = temp;
	}

	sort(strowes.begin(), strowes.end(), greater<int>());

	int result = -1;
	for (int i = 0; i < n - 2 ; ++i) {
		if (strowes[i] < strowes[i + 1] + strowes[i + 2]) {
			result = strowes[i] + strowes[i + 1] + strowes[i + 2];
			break;
		}
	}

	cout << result << endl;
	return 0;
}