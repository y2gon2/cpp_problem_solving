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

	priority_queue<int, vector<int>, greater<int>> pq; // 내림차순 최소 힙 (힙 구조이므로 최상단 (외곽) 값이 가장 작은 값이 된다.)

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

			// 힙의 크기가 n 보다 커지면 그 위로 노출된 값 (크기로 내림차순하여 n 번째 값보다 작은 값) 은 탈락 시킴
			if ((int)pq.size() > n) {
				pq.pop();
			}
		}
	}

	// 최종 정리된 최소 힙 구조에서 최상단 (n 번째 크기 값) 을 출력
	cout << pq.top() << endl;
	return 0;
}
