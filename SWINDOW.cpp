#include <bits/stdc++.h>
#define maxn 1000000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

long z[2*maxn], tbegin[maxn], tend[maxn];
set<string> Set;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string t, p, s;
	long k, l, r;
	getline(cin, t);
	getline(cin, p);
	cin >> k;
	
	s = p+t;
	
	z[0] = 0;
	l = 0;
	r = 0;
	
	long lengths = s.length();
	FOR(i, 1, lengths-1) {
		if (i>r) {
			l = i;
			FOR(j, i, lengths-1) if (s[j-i]==s[j]) r = j; else break;
			z[i] = r-l+1;
		}
		else{
			long k = i-l;
			if (z[k]>r-i) {
				l = i;
				FOR(j, r+1, lengths-1) if (s[j-i]==s[j]) r = j; else break;
				z[i] = r-l+1;
			}
			else z[i] = z[k];
		}
	}
	
	//FOR(i, 1, lengths-1) cout << z[i] << endl;
	
	long lengthp = p.length();
	long index = 0;
	FOR(i, lengthp, lengths-1) 
	if (z[i]>=lengthp) {
		index++;
		tbegin[index] = i-lengthp;
		tend[index] = i-1;
	}
	
	long pointer = 1;
	long n = t.length();
	FOR(i, 1, n-k+1) {
		if (i-1>tbegin[pointer] && pointer<=index) pointer++;
		if (pointer>index) break;
		if (i+k-2<tend[pointer]) continue;
		
		Set.insert(t.substr(i-1, k));
	}	
	
	cout << Set.size();
	return 0;
}
