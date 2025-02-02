#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// https://www.acmicpc.net/problem/5549
// 행성 탐사

struct types {
	int jungle;
	int ocean;
	int iced;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n, k;
	cin >> m >> n >> k;
	cin.ignore();
	
	vector<vector<types>> map(m + 1, vector<types>(n + 1, {0, 0, 0}));
	for (int y = 1; y <= m; ++y) {
		string input;
		getline(cin, input);

		for (int x = 1; x <= n; ++x) {
			map[y][x].iced = map[y - 1][x].iced + map[y][x - 1].iced - map[y - 1][x - 1].iced;
			map[y][x].jungle = map[y - 1][x].jungle + map[y][x - 1].jungle - map[y - 1][x - 1].jungle;
			map[y][x].ocean = map[y - 1][x].ocean + map[y][x - 1].ocean - map[y - 1][x - 1].ocean;

			char t = input[x - 1];
			if (t == 'J') {
				++map[y][x].jungle;
			}
			else if (t == 'O') {
				++map[y][x].ocean;
			}
			else if (t == 'I') {
				++map[y][x].iced;
			}
		}
	}

	for (int e = 0; e < k; ++e) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int iced = map[c][d].iced - map[a - 1][d].iced - map[c][b - 1].iced + map[a - 1][b - 1].iced;
		int jungle = map[c][d].jungle - map[a - 1][d].jungle - map[c][b - 1].jungle + map[a - 1][b - 1].jungle;
		int ocean = map[c][d].ocean - map[a - 1][d].ocean - map[c][b - 1].ocean + map[a - 1][b - 1].ocean;

		cout << jungle << ' ' << ocean << ' ' << iced << '\n';
	}
	return 0;
}