// https://www.acmicpc.net/problem/2075
// 2075 N번째 큰 수

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>

using namespace std;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<int>> pq;

	int n;
	cin >> n;
	cin.ignore();


	string input;
	int num;

	for (int i = 0; i < n; i++) {
		getline(cin, input);

		stringstream ss(input);

		for (int j = 0; j < n; j++) {
			ss >> num;
			pq.push(num);

			if ((int)pq.size() > n) {
				pq.pop();
			}
		}
	}

	cout << pq.top() << endl;
	return 0;
}
