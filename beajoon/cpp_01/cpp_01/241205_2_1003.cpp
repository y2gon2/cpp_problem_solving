// �Ǻ���ġ �Լ�
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> numbers;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}

	auto max_iter = max_element(numbers.begin(), numbers.end());

	int mx = *max_iter;

	vector<int> zeros(mx + 1, 0);
	vector<int> ones(mx + 1, 0);

	// fibo 0 �� ��, ���� 0�� ����, 1�� ����
	zeros[0] = 1;
	ones[0] = 0;

	// fibo 1 �� ��, ���� 0�� ����, 1�� ����
	zeros[1] = 0;
	ones[1] = 1;

	for (int i = 2; i <= mx; i++) {
		zeros[i] = zeros[i - 1] + zeros[i - 2];
		ones[i] = ones[i - 1] + ones[i - 2];
		//cout << "zero " << i << " : " << zeros[i] << endl;
		//cout << "ones " << i << " : " << ones[i] << endl;
	}

	//cout << "mx : " << mx << endl;

	for (int i = 0; i < n; i++) {
		int num = numbers[i];
		cout << zeros[num] << ' ' << ones[num] << endl;
	}
	return 0;
}