#include <bits/stdc++.h>
#define maxn 1000000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

vector<long> z(string s) {
	long l, r;
	long N = s.length();
	
	vector<long> ans(N);
	ans[0] = N;
	l = r = 0;
	FOR(i, 1, N-1) {
		if (i>r) {
			l = i; r = i-1;
			FOR(j, i, N-1) if (s[j-i]==s[j]) r = j; else break;
			ans[i] = r-l+1;
		}
		else {
			long k = i-l;
			if (ans[k]<=r-i) ans[i] = ans[k];
			else {
				l = i;
				FOR(j, r+1, N-1) if (s[j-i]==s[j]) r = j; else break;
				ans[i] = r-l+1;
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long n, l, r, pos;
	string s, a, b;
	cin >> a;
	cin >> b;
	
	s = b+a;
	long lengthb = b.length();
	vector<long> ans = z(s);
	
	pos = lengthb;
	for (auto iter = ans.begin()+lengthb; iter!=ans.end(); iter++) {
		if (*iter>=lengthb) {
			cout << pos - lengthb+1 << " ";	
		}
		pos++;
	}
	
	return 0;
}
