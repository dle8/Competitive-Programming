#include <bits/stdc++.h>
using namespace std;

int n;
int s[] = {6, 6, 2, 6, 4, 2, 2, 4, 2, 8};
int unitDigit[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int powerTwo[] = {6, 2, 4, 8};

long long lastDigit(int n) {
	if (n<10) return unitDigit[n];
	int k = n/10;
	int i = n%10;
	int r = (2*k)%4;
	if (i<5) return (lastDigit(2*k)* powerTwo[r]*s[i]);
	return (lastDigit(2*k+1)*powerTwo[r]*s[i]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long result;
	cin >> n;
	result = lastDigit(n);
	while (result%10==0) result = result/10;
	cout << result%10;
	return 0;
}
