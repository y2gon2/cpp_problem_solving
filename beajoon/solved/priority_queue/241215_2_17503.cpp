#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/17503
// 17503 맥주 축제


struct SecondDown {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		return a.second > b.second; // 두번째 값(도수) 가 낮은 것이 위로 (오름차순)
	}
};

struct FirstUp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		return a.first > b.first; // 첫번째 값(선호도) 가 낮은 것이 위로 (오름차순)
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int acc = 0;
	int level = 0;
	bool flag = false;

	// 최초 입력 값들에서 레벨이 낮은 것 순으로 추출할 수 있도록 정렬 입력
	priority_queue<pair<int, int>, vector<pair<int, int>>, SecondDown> pq;
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i) {
		int v, c;
		cin >> v >> c;
		pq.push({ v, c });
	}

	// 레벨이 낮은 순으로 모은 n 개의 맥주에서
	// 선호도 값이 낮은거를 꺼내고 다른 맥주를 추가할 수 있도록 정렬 입력
	priority_queue<pair<int, int>, vector<pair<int, int>>, FirstUp> combination;

	for (int i = 0; i < n; ++i) {
		auto t = pq.top();
		pq.pop();

		combination.push(t);
		acc += t.first;
		level = t.second;
	}

	if (acc >= m) {
		cout << level << '\n';
		flag = true;
	}
	else {
		while (!pq.empty()) {
			// cout << "acc : " << acc << ", level : " << level << '\n';
			auto t = pq.top();
			pq.pop();

			auto remove = combination.top();
			combination.pop();
			combination.push(t);

			acc -= remove.first;
			acc += t.first;
			level = t.second;

			if (acc >= m) {
				cout << level << '\n';
				flag = true;
				break;
			}

		}
	}

	if (!flag) {
		cout << -1 << '\n';
	}

	/*for (int i = 0; i < k; ++i) {
		int v, c;
		auto  t = pq.top();
		pq.pop();
		cout << t.first << ", " << t.second << '\n';
	}*/

	return 0;
}