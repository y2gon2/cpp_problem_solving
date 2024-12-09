#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// https://www.acmicpc.net/problem/11256
// 11256 사탕

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cout.tie(NULL);
	cout.sync_with_stdio(false);
	
	int n;

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; ++i) {
		int candy, box_num;
		string input;
		getline(cin, input);
		size_t split_point = input.find(' ');

		candy = stoi(input.substr(0, split_point));
		box_num = stoi(input.substr(split_point + 1));
		vector<int> boxes(box_num, 0);

		for (int j = 0; j < box_num; ++j) {
			string box_info;
			getline(cin, box_info);
			size_t split_p = box_info.find(' ');

			int w = stoi(box_info.substr(0, split_p));
			int h = stoi(box_info.substr(split_p + 1));

			boxes[j] = w * h;
		}

		sort(boxes.begin(), boxes.end(), greater<int>());

		int result = 0;
		while (candy > 0) {
			candy = candy - boxes[result++];
		}
		cout << result << endl;
	}
}