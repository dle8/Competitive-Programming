#include <iostream>

using namespace std;

int result;
int minN;

void tryMin(int x) {
	if (x<0) {
		result--;
		return;
	}
	if (x==0) {
		if (result < minN) minN = result;	
	}
	else {
		result++;
		tryMin(x-5);
		result++;
		tryMin(x-3);
	}
}

int main() {
	int n;
	cin >> n;
	result = 0;
	minN = 1001;
	tryMin(n);
	if (minN == 1001) cout << -1;
	else cout << minN;
	return 0;
}
