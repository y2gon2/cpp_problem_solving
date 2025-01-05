#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// https://www.acmicpc.net/problem/9251
// LCS

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	int l1 = s1.size();
	int l2 = s2.size();

	vector<int> row(l2 + 1, 0);
	vector<vector<int>> table(l1 + 1, row);

	for (int i = 1; i < l1 + 1; ++i) {
		for (int j = 1; j < l2 + 1; ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else {
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}
	cout << table[l1][l2] << '\n';
	return 0;
}

// 풀이 과졍 (by ChatGPT)
//동적 계획법(Dynamic Programming)으로 최장 공통 부분 수열(LCS)을 구하는 전형적인 아이디어는 다음과 같은 단계로 요약할 수 있다 :
//
//1. DP 테이블 정의
//* 문자열 A의 길이를 N, B의 길이를 M이라 하자.
//* 2차원 배열 dp를(N + 1) x(M + 1) 크기로 선언한다.
//* dp[i][j]는 “A의 앞쪽에서 i개의 문자”와 “B의 앞쪽에서 j개의 문자”를 고려했을 때, 만들 수 있는 최장 공통 부분 수열(LCS)의 길이”를 저장한다.
//
//2. 초기값 설정
//* dp[0][j]는 A 문자열에서 아무 문자를 고르지 않은 상태이므로 0
//* dp[i][0]는 B 문자열에서 아무 문자를 고르지 않은 상태이므로 0
//* 따라서 테이블의 첫 행과 첫 열을 모두 0으로 초기화한다.
//
//3. 점화식
//* 두 문자가 같은 경우 : A[i - 1] == B[j - 1]
//  - dp[i][j] = dp[i−1][j−1] + 1
//
//*두 문자가 다른 경우 :
//  - dp[i][j] = max(dp[i−1][j], dp[i][j−1])
//
//* 문자 비교 시에, dp[i][j]가 A의 i번째와 B의 j번째가 아니라, 인덱스가 1부터 시작한다고 가정했기 때문에 실제 배열에 접근할 때는 A, B 인덱스가 각각 i - 1, j - 1이 됨에 유의한다.
//
//4. 최종값
//* dp[N][M]이 두 문자열 A와 B의 LCS 길이가 된다.
//
// 5. 결론
// -> 두 문자열 내에서 LCS 길이를 추정하는것을 각 문자열 첫번째
//    문자부터 각 문자열 마지막 문자까지 비교해본다고 가정하면
//    l1 * l2 경우의 수가 존재한다. 
//    
//    테이블을 (l1 + 1) * (l2 + 1) 로 준비한다.
//    아직 상대 문자열과 비교하지 않은 dp[i][0], dp[0][j] 
//    값들은 모두 0 일 것이다.
//
//    해당 값을 사용하여 각 경우의 수를 모두 비교하며 나머지 칸을
//    채운다. 
//    
//    만약 문자열1[i] == 문자열2[j] 이면 
//    - dp[i][j] = dp[i−1][j−1] + 1
//
//    문자열1[i] != 문자열2[j] 이면 
//    - dp[i][j] = max(dp[i−1][j], dp[i][j−1])
//
//   이렇게 dp[l1 + 1][l2 + 1] 까지 비교 후 마지막 칸의 값이 곧
//   LCS 이다. 

