#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/1141
// 접두사

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<string> words(n);
	for (string& w : words) {
		cin >> w;
	}

	sort(words.begin(), words.end());

	string prev_w = words[0];
	int prev_len = prev_w.length();
	int count = n;

	for (int i = 1; i < n; ++i) {
		string cur_w = words[i];
		int cur_len = cur_w.length();

		if (prev_len > cur_len) {
			prev_w = cur_w;
			prev_len = cur_len;
		}
		else {
			//cout << cur_w << '\n';
			if (prev_w == cur_w.substr(0, prev_len)) {
				--count;
			}
			prev_w = cur_w;
			prev_len = cur_len;
		}
	}
	cout << count << '\n';
	return 0;
}