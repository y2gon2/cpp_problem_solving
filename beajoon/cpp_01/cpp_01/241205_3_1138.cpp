// https://www.acmicpc.net/problem/1138
// �� �ٷ� ����

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
			// �̹� ������ �ش� �ٿ� ������ ��ĭ�� �и���.
			if (numbers[j] > 0) {
				order++;
			}
			// �ش� ���� ����ְ�, ������ ������ ������ �ش� ��ġ�� �����ȴ�.
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