#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<bool> winner(n + 1, true);

	if (n > 1) {
		winner[2] = false;
	}

	for (int i = 5; i < n + 1; i++) {
		winner[i] = (!winner[i - 1]) or (!winner[i - 3] or (!winner[i - 4]));
	}

	if (winner[n]) {
		cout << "SK" << endl;
	} 
	else {
		cout << "CY" << endl;
	}

	return 0;
}