#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 1000010
using namespace std;

long posx[maxn], posy[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long lengths, lo, lt, neo;
	long long res;
	string s;
	char x, y;
	
	getline(cin, s);
	cin >> x >> y;
	
	lengths = s.length();
	lo = 0;
	lt = 0;
	FOR(i, 0, lengths-1) {
		if (s[i]==x) posx[++lo] = i+1;
		if (s[i]==y) posy[++lt] = i+1;
	}
	
	neo = 1;
	res = 0;
	FOR(i, 1, lo) {
		while (posy[neo]<=posx[i] && neo<=lt) neo++;
		if (neo<=lt) res+=(lt+1-neo);
	}
	cout << res;
	return 0;
}
