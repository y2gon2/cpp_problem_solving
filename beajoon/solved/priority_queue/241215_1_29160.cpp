#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/29160
// 29160 나의 FIFA 팀 가치는? 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	vector<priority_queue<int, vector<int>, less<int>>> players(11);

	for (int i = 0; i < n; ++i) {
		int num, value;
		cin >> num >> value;

		if (num == 1) players[0].push(value);
		else if (num == 2) players[1].push(value);
		else if (num == 3) players[2].push(value);
		else if (num == 4) players[3].push(value);
		else if (num == 5) players[4].push(value);
		else if (num == 6) players[5].push(value);
		else if (num == 7) players[6].push(value);
		else if (num == 8) players[7].push(value);
		else if (num == 9) players[8].push(value);
		else if (num == 10) players[9].push(value);
		else players[10].push(value);
	}

	int total = 0;
	for (int i = 0; i < k; ++i) {
		total = 0;
		for (auto& p : players) {
			if (!p.empty()) {
				int h1 = p.top();
				p.pop();

				if (h1 > 0) p.push(--h1);
				else p.push(0);

				total += p.top();
			}
		}
	}

	cout << total << '\n';
	return 0;
}