#include <iostream>
#include <string>

using namespace std;
int N = 8;

int main() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++) {
			if ((i + j) % 2 == 0) {
				if (temp[j] == 'F') {
					result++;
				}
			}
			// cout << i << ", " << j << ': ' << temp[j] << endl;
		}
	}
	cout << result << endl;
	return 0;
}