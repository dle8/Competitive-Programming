#include <bits/stdc++.h>
#define oo 1e9
#define maxn 100000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

long z[2*maxn];

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a, b, s;
	long l, r;
	cin >> a >> b;
	s = b+a;
	
	z[0] = 0;
	l = 0;
	r = 0;
	long lengths = s.length();
	FOR(i, 1, lengths-1) {
		if (i>r) {
			l = i;
			r = i-1;
			FOR(j, i, lengths-1) if (s[j-i]==s[j]) r = j; else break;
			z[i] = r-l+1;
		}
		else {
			long k = i-l;
			if (z[k]>r-i) {
				l = i;
				FOR(j, r+1, lengths-1) if (s[j-i]==s[j]) r = j; else break;
				z[i] = r-l+1;
			}
			else z[i] = z[k];
		}
	}
	
	long lengthb = b.length();
	long res = 0;
	FOR(i, lengthb, lengths-1) 
		if (z[i]==lengths-i) {
			res = min(z[i], lengthb);
			break;
		}
	
	cout << a + b.substr(res);
		
	
	return 0;
}
