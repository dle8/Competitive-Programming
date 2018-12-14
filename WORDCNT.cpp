#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)

using namespace std;

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string input, buf;
	long res, test_cases, count, lg, sz, w[10000+10], index;
	bool flag;
	cin >> test_cases;
	cin.ignore();
	FOR(current_test, 1, test_cases) {
		getline(cin, input);
		istringstream iss(input, istringstream::in);
		//stringstream ss(input);
		index = 0;
		while (iss>>buf) {
			lg = buf.length();
			w[++index] = lg;
		}
		count = 0;
		res = 0;
		w[index+1] = -1;
		FOR(i, 1, index) {
			count++;
			if (w[i]!=w[i+1]) {
				res = max(res, count);
				count = 0;
			}
		}
		if (current_test!=test_cases) cout << max(res, count) << "\n";
		else cout << max(res, count);
	}
	return 0;
}
