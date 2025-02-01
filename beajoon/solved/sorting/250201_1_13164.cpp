#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/13164
// 행복 유치원 (sorting + greedy)
// 순서대로 키의 차이를 오름차순 queue 에 넣고 (n - 1 개) 
// 마지막에 k 만큼을 빼고 다 더한다.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	int count = (n - 1) - k; 

	priority_queue<int, vector<int>, greater<int>> pq;

	int prev;
	cin >> prev;

	for (int i = 0; i < n - 1; ++i) {
		int num;
		cin >> num;

		pq.push(num - prev);
		prev = num;
	}

	int result = 0;
	while (!pq.empty()) {
		if (count >= 0) {
			result += pq.top();
			pq.pop();
			--count;
		}
		else {
			break;
		}
	}

	cout << result << '\n';
	return 0;
}