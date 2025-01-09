#include <iostream>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/2302
// 극장 좌석

// 일반석이 a 개 연속될 경우, 해당 a 개 석에 대해서는 다음의 경우의 수가 존재 하게 된다. 
// a == 0 -> 1  (모두 고정석이어도 앉을 수 있는 경우의 수 1 존재)
// a == 1 -> 1
// a == 2 -> 2
// a == 3 -> 3
// a == 4 -> a(3) + a(2)
// a == 5 -> a(4) + a(3)
// => 점화식 a(n) = a(n - 1) + a(n - 2)

// 연속된 자유석에서 발생한 경우의 수끼리 곱하면 각각의 경우의 수를 모두 구할 수 있다. 
// 따라서 문제 예제의 경우 고정석 X 자유석 O 로 표시하면 전체 9열이
//   
//  O O O X O O X O O
//
// 이므로 연속된 경우가 a(3) * a(2) * a(2)  이므로 전체 경우의 수는 
//  3 * 2 * 2 = 12 가 된다. 

const int LIMIT = 41;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<long long> nums(LIMIT, 0);
	nums[0] = 1;
	nums[1] = 1;
	nums[2] = 2;
	nums[3] = 3;

	for (int i = 4; i < LIMIT; ++i) {
		nums[i] = nums[i - 1] + nums[i - 2];
	}

	int n, m;
	cin >> n >> m;

	long long result = 1;
	int prev_vip = 0;

	for (int i = 0; i < m; ++i) {
		int vip;
		cin >> vip;
		result *= nums[vip - prev_vip - 1];
		prev_vip = vip;
	}

	//cout << "last vip " << prev_vip << '\n';
	result *= nums[n + 1 - prev_vip - 1];

	cout << result << '\n';
	return 0;
}

