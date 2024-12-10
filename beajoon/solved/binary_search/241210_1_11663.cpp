#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/11663
// 11663 선분 위의 점
// 참고 : https://velog.io/@jh991012/%EB%B0%B1%EC%A4%80c-11663%EB%B2%88-%EC%84%A0%EB%B6%84-%EC%9C%84%EC%9D%98-%EC%A0%90


int binary_search(int a, const vector<int>& points, int n, bool under) {
	int left = 0;
	int right = n - 1;
	int result = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (points[mid] <= a) {
			left = mid + 1;
			result = mid + 1;

			if (points[mid] == a && under) {
				return result - 1; // under 의 경우 나중에 뺄셈 값으로 사용되므로, 만약 a 과 일치하는 포인트가 존재하다면 이를 제외 시킴
			}
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cout.tie(NULL);
	cout.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> points(n, 0);

	for (int i = 0; i < n; ++i) {
		cin >> points[i];
	}

	sort(points.begin(), points.end());

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		int underIdx = binary_search(a, points, n, true);
		int overIdx = binary_search(b, points, n, false);

		cout << overIdx - underIdx << '\n';
		//cout << "overIdx : " << overIdx << ", underIdx : " << underIdx << '\n';

		//cout << upper_bound(points.begin(), points.end(), b) - lower_bound(points.begin(), points.end(), a) << '\n';
	}
	return 0;
}