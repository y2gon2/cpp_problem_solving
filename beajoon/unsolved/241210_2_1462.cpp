#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// https://www.acmicpc.net/problem/14627
// 14627 파닭파닭

int binary_search(int c, const vector<int>& pa_list) {
	int left = 1;
	int right = pa_list[pa_list.size() - 1];
	int result = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int count = 0;
		
		for (int i = 0; i < pa_list.size(); ++i) {
			count += pa_list[i] / mid;
		}
		//cout << "left : " << left << ", mid : " << mid << ", right : " << right << ", count : " << count << '\n';

		if (count >= c) {
			left = mid + 1;
			result = mid;
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

	int s, c;
	cin >> s >> c;

	vector<int> pa_list(c, 0);
	ll sum = 0;

	for (int i = 0; i < s; ++i) {
		int num;
		cin >> num;
		pa_list[i] = num;
		sum += num;
	}

	sort(pa_list.begin(), pa_list.end());

	int cut = binary_search(c, pa_list);
	//cout << "cut : " << cut << '\n';

	cout << sum - (cut * c) << '\n';

	return 0;
}