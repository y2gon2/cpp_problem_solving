// https://www.acmicpc.net/problem/2751
// 2751 수 정렬하기 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	std::cin.tie(NULL);         // 불필요한 플러시 방지
	std::cout.tie(NULL);        // 불필요한 플러시 방지
	
    // C++ 표준 입출력(std::cin, std::cout)과 C 스타일 입출력(scanf, printf)은 기본적으로 동기화(sync)되어 있음. 
    // 이 동기화는 C++과 C 라이브러리의 출력 버퍼를 일치시키는 역할하는데, 
    // 해당 동기화를 해제하여 표준 입출력의 독립성을 보장하고, 더 빠르게 작동하도록 함.
    cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	int n;
	cin >> n;
	cin.ignore();

	vector<int> numbers(n, 0);
	int temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		numbers[i] = temp;
	}

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < n; i++) {
		cout << numbers[i] << '\n'; // 직접 출력
	}

	return 0;
}