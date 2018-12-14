#include <bits/stdc++.h>
#define FORU(i, l, r) for(int i=l; i<=r; i++)
#define maxn 1000000+10
using namespace std;

long z[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long lengths, l, r;
	string s;
	cin >> s;
	
	z[0] = 0;
	lengths = s.length();
	l = 0;
	r = 0;
	FORU(i, 1, lengths-1) {
		if (i>r) {
			l = i;
			FORU(j, i, lengths-1) if (s[j-i]==s[j]) r = j; else break;
			z[i] = r-l+1;
		}
		else {
			long k = i-l;
			if (z[k]>r-i) {
				l = i;
				FORU(j, r+1, lengths-1) if (s[j-i]==s[j]) r = j; else break;
				z[i] = r-l+1;
			}
			else z[i] = z[k];
		}
	}
	
	FORU(i, 1, lengths-1) if (z[i]==(lengths-i)) return cout << s.substr(0, i), 0;
}
