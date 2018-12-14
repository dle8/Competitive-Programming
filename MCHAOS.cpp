#include <bits/stdc++.h>
#define maxn 100000+10
#define FORU(i, l, r) for (int i=l; i<=r; i++)
#define FORD(i, r, l) for (int i=r; i>=l; i--)
using namespace std;

typedef long long ll;

string str[maxn], rstr[maxn];
long n;
ll ft[maxn];
unordered_map<string, long> pos;
unordered_map<string, string> rverse;

void update(long i) {
	for(; i<=n; i+=(i&(-i))) ft[i]++;
}

ll getSum(long i) {
	ll sum = 0;
	for(; i>0; i-=(i&(-i))) sum+=ft[i];
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	FORU(i, 1, n) {
		cin >> rstr[i];
		str[i] = rstr[i];
		
		reverse(rstr[i].begin(), rstr[i].end());	
		rverse[str[i]] = rstr[i];
	}
	
	sort(str+1, str+1+n);
	sort(rstr+1, rstr+1+n);
	
	FORU(i, 1, n) pos[rstr[i]] = i;
	
	ll res = 0;
	FORD(i, n-1, 1) {
		update(pos[rverse[str[i+1]]]);
		res+=getSum(pos[rverse[str[i]]]-1);
	}
	
	return cout << res, 0;
}
