#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/20922
// 겹치는 건 싫어

const int LIMIT = 2000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> input(n);
	vector<int> nums(LIMIT, 0);

	int len = 0;
	int result = len;

	for (int& i : input) {
		cin >> i;
	}
	
	for (int right = 0; right < n; ++right) {
		int r_num = input[right];
		// 제한 갯수에 아직 차지 않았다면 여기에 더하고 길이를 늘림
		if (nums[r_num] < k) {
			++nums[r_num];
			++len;
		}
		// 제한 갯수가 이미 다 찼다면, 동일 숫자 갯수가 빠질 때까지 left 를 줄임
		else {
			for (int left = right - len; left < right; ++left) {
				int l_num = input[left];
				
				// 동일 숫자인 경우, 제한에 걸린 숫자에 대해 이미 뺐을 것이므로
				// 빠져나감
				if (l_num == r_num) {
					// 동일 숫자인 경우 right 를 제거하고 left 를 추가하게된다.
					// 이는 곧 동일 숫자에 대한 count 및 동일 길이를 유지하므로
					// 그대로 둠
					break;
				}
				else {
					// left 를 계속 제거함.
					--nums[l_num];
					--len;
				}
			}
		}
		//for (int left = right - (len - 1); left <= right; ++left) {
		//	cout << input[left] << ' ';
		//}
		//cout << ",  len: " << len << '\n';

		result = max(result, len);
	}

	cout << result << '\n';
	return 0;
}