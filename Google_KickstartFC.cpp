#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	bool flag;
	long test_cases;
	long long l, n, k, to;
	
//	freopen("C-small-attempt1.in", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cout << "Case #" << current_test << ": ";
		
		cin >> l >> n >> k;
		flag = false;
		FOR(ch, 1, l) {
			FOR(thay, 0, n-2) {
				if ((n-thay)%2==0) to = n;
				else to = n-1;
				for (int j=thay+2; j<=to; j+=2) {
					FOR(i, 1, l) {
						if (i==ch && j==3) {
							FOR(i, 1, n) {
								k--;
								if (k==0) {
									cout << i;
									flag = true;
								}
								if (flag) break;
							}
						}
						else {
							k--;
							if (k==0) {
								cout << j;
								flag = true;
							}
							if (flag) break;
						}
						if (flag) break;
					}
					if (flag) break;
				}
				if (flag) break;
			}
			if (flag) break;
		}
		
		if (k!=0) cout << 0;
		cout << "\n";
	}
	return 0;
}
