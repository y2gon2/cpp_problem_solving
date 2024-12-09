#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/17266
// 17266 어두운 굴다리
// 카테고리는 이분 탐색인데, 일반 정렬이나 그리디 탐색으로 푸는게 좀더 효율적인듯...

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int mx = 0;
	int n, m;
	cin >> n;
	cin >> m;
	cin.ignore();

	if (m == 1) {
		int k;
		cin >> k;

		mx = max(k, n - k);
	}
	else {
		string input;
		getline(cin, input);
		stringstream ss(input);

		int prev = 0;

		for (int i = 0; i < m; ++i) {
			int curr;
			ss >> curr;

			int half = ((curr - prev) % 2 == 0) ? (curr - prev) / 2 : (curr - prev) / 2 + 1;

			if (i == m - 1) {
				mx = max(mx, half);
				mx = max(mx, n - curr);
			}
			else if (i == 0) {
				mx = max(mx, curr);
			}
			else {
				mx = max(mx, half);
			}

			prev = curr;
		}
	}
	cout << mx << endl;


	return 0;
}