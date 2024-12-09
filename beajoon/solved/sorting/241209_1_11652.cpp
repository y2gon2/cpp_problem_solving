#include <iostream>
#include <map>

// https://www.acmicpc.net/problem/11652
// 11652 카드

using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cout.tie(NULL);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;

	map<long long, int> card_map;

	long long temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;

		(card_map.count(temp) > 0) ? card_map[temp]++ : card_map[temp] = 1;
	}

	long long result;
	int mx = 0;
	for (auto it = card_map.begin(); it != card_map.end(); ++it) {
		if (it->second > mx) {
			result = it->first;
			mx = it->second;
		}
	}

	cout << result << endl;

	return 0;
}