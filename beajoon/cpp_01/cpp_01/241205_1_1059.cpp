#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	int result = 0;
	int n;
	cin >> n;
	cin.ignore();

	string input;
	getline(cin, input);
	stringstream ss(input);

	vector<int> numbers;
	int num;

	while (ss >> num) {
		numbers.push_back(num);
	}

	int a;
	cin >> a;

	sort(numbers.begin(), numbers.end());
	
	for (int i = 0; i < n ; i++) {
		if (numbers[i] > a) {
			int mx = numbers[i];
			int mn = (i > 0) ? numbers[i - 1] : 0;
			int whole_pairs = (mx - mn - 1) * (mx - mn - 2) / 2;
			int front_pairs = (a - mn > 1)? (a - mn - 1) * (a - mn - 2) / 2 : 0;
			int rear_pairs = (mx - a > 1)? (mx - a - 1) * (mx - a - 2) / 2 : 0;

			//cout << "whole_pairs : " << whole_pairs << endl;
			//cout << "front_pairs : " << front_pairs << endl;
			//cout << "rear_pairs : " << rear_pairs << endl;

			result = whole_pairs - front_pairs - rear_pairs;
			break;
		}
	}

	cout << result << endl;
	
	return 0;
}