#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 1000+100
using namespace std;

long f[maxn];

int main() {
	long test_cases, n;
	
	long divi = 1, count = 0, temp = 0;
	FOR(i, 1, 1000000) {
		if (i%divi==0) {
			count++;
			if (count>1000) break;
			f[count] = i;
			temp++;
		}
		if (temp==divi) {
			divi++;
			temp = 0;
		}
	}
	
	ifstream fi; ofstream fo;
	fi.open("input.txt"); fo.open("output2.txt");
	
	fi >> test_cases;
	FOR(current_test, 1, test_cases) {
		fi >> n;
		fo << "Case #" << current_test<< ": " << f[n] << ", n = " << n << "\n";	
	}
	fi.close();
	fo.close();
	return 0;
}
