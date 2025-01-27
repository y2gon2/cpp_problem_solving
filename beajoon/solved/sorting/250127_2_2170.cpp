#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/2170
// 선 긋기

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> lines(n);
	for (auto& l : lines) {
		cin >> l.first >> l.second;
	}

	sort(lines.begin(), lines.end());

	int result = 0;
	int start = lines[0].first;
	int end = lines[0].second;

	for (int i = 1; i < n; ++i) {
		if (end < lines[i].first) {
			result += abs(end - start);
			start = lines[i].first;
			end = lines[i].second;
		}
		else if (end < lines[i].second) {
			end = lines[i].second;
		}
	}

	cout << result + abs(end - start) << '\n';
	return 0;
}