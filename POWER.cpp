#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define eps 1e-9
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long test_cases;
	long long l, r, floor;
	float lp, rp;
	
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cout << "Case #" << current_test <<": ";
		cin >> l >> r;
		REP(i, 40, 1) {
			float lp = (float) pow(l, 1.0/i);
			float rp = (float) pow(r, 1.0/i);
			
			floor = rp;
			if (lp-floor<eps) {
				cout << i;
				break;
			}
		}
		cout << "\n";
	}
	return 0;
}
