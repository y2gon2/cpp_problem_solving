//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int CH_A = int('A');
//int CH_a = int('a');
//
//int main() {
//	int arr[26] = {0, };
//	string input;
//
//	getline(cin, input);
//	
//	int n = input.length();
//
//	for (int i = 0; i < n; i++) {
//		int ch = int(input[i]);
//		
//		if (ch < CH_a) {
//			arr[ch - CH_A]++;
//		} 
//		else {
//			arr[ch - CH_a]++;
//		}
//	}
//
//	int  mx_ch = 0;
//
//	for (int i = 0; i < 26; i++) {
//		mx_ch = (arr[i] > mx_ch) ? arr[i] : mx_ch;
//	}
//
//	int count = 0;
//	for (int i = 0; i < 26; i++) {
//		if (arr[i] == mx_ch) {
//			count++;
//		}
//	}
//
//	if (count > 1) {
//		cout << '?' << endl;
//	}
//	else {
//		for (int i = 0; i < 26; i++) {
//			if (arr[i] == mx_ch) {
//				char result = static_cast<char>(i + CH_A);
//				cout << result << endl;
//				break;
//			}
//		}
//	}
//
//	return 0;
//}


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> alpha(26, 0);
	string input;

	getline(cin, input);

	for (char ch : input) {
		if (isalpha(ch)) {
			ch = toupper(ch);
			alpha[ch - 'A']++;
		}
	}

	int mx_ch = *max_element(alpha.begin(), alpha.end());
	int mxCount = count(alpha.begin(), alpha.end(), mx_ch);

	if (mxCount > 1) {
		cout << '?' << endl;
	}
	else {
		char result = distance(alpha.begin(), find(alpha.begin(), alpha.end(), mx_ch) + 'A');
		cout << result << endl;
	}

	return 0;
}