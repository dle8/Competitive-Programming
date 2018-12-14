#include <iostream>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

bool isPrime(long long int n) {
	if (n==2 || n==3) return true;
	for (int i=2; i<=sqrt(n); i++)
		if (n%i==0) return false;
	return true;
}

int main() {
	int k, kq, i, dem;
	cin >> k;
	kq = 0;
	i = 2;
	dem = 0;
	string s, s2;
	long long int j;
	
	while (kq<k) {
		if (isPrime(i)) {
			dem++;
			stringstream ss;//chuyen tu int sang string
			ss << i;
			string s = ss.str();
			if (dem%2==0) {
				j = stoll(s2+s);//chuyen tu string sang long long int
				if (isPrime(j)) kq++;
				dem = 0;
			} else s2 = s;
		}
		i++;
	}
	cout << j;
	return 0;
}
