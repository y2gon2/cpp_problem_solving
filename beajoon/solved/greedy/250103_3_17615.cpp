#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// https://www.acmicpc.net/problem/17615
// 볼 모으기

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int result = 0;
	
	int n;
	cin >> n;
	cin.ignore();
	
	string input;
	getline(cin, input);

	// 오른쪽 방향으로 모았을 때 최소 이동 수 구하기
	int same_last = 0;
	int opposite_last = 0;
	
	char last = input[n - 1];
	int from_move = 0;

	for (int i = n - 2; i >= 0; --i) {
		if (input[i] != last) {
			from_move = i;
			break;
		}
	}

	for (int i = from_move; i >= 0; --i) {
		(input[i] == last) ? ++same_last : ++opposite_last;
	}

	int move_right = min(same_last, opposite_last);

	// 왼쪽 방향으로 모았을 때 최소 이동 수 구하기
	int same_first = 0;
	int opposite_first = 0;

	char first = input[0];
	int start_move = 0;

	for (int i = 1; i < n; ++i) {
		if (input[i] != first) {
			start_move = i;
			break;
		}
	}

	for (int i = start_move; i < n; ++i) {
		(input[i] == first) ? ++same_first : ++opposite_first;
	}

	int move_left = min(same_first, opposite_first);

	cout << min(move_right, move_left) << '\n';
	return 0;
}