// https://www.acmicpc.net/problem/1138
// 한 줄로 서기

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();

	string input;
	getline(cin, input);
	
	stringstream ss(input);
	vector<int> numbers(n, 0);

	int order;
	for (int i = 1; i <= n; i++) {
		ss >> order;

		for (int j = 0; j < n ; j++) {
			// 이미 누군가 해당 줄에 있으면 한칸씩 밀린다.
			if (numbers[j] > 0) {
				order++;
			}
			// 해당 줄이 비어있고, 본인의 순서가 맞으면 해당 위치에 선정된다.
			else if (order == j) {
				numbers[j] = i;
			}
		}
	}

	for (auto num = numbers.begin(); num != numbers.end(); ++num) {
		cout << *num;
		if (num != numbers.end() - 1) {
			cout << ' ';
		}
	}

	return 0;
}