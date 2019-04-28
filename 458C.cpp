#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define fi first
#define se second
#define maxn 100000+10
#define oo 1000000000
using namespace std;


typedef pair<long, long> pll;
long n, num[maxn]; 
pll vote[maxn];
bool check[maxn];

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

long max(long a, long b) {
	if (a>=b) return  a;
	else return b;
}

bool cmp(const pll&x, const pll&y) {
	return ((x.fi<y.fi) || (x.fi==y.fi && x.se<y.se));
}

long f(long t) {
	long price = 0, neo, remainder;
	neo = oo;
	memset(check, true, sizeof(check));
	FOR(i, 1, n) 
	if (num[vote[i].fi]>=t && neo!=vote[i].fi) {
		remainder = num[vote[i].fi+1-t];
		neo = vote[i].fi;
		long j = i;
		while (remainder && vote[j].fi==neo) {
			price+=vote[j].se;
			remainder--;
			check[j] = false;
		}
	}
	
	remainder = t-num[0];
	neo = 0;
	while (remainder>0) {
		if (check[++neo]) {
			price+=vote[neo].fi;
			check[neo] = false;
			remainder--;
		}
	}
	
	return price;	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long left, right;
	cin >> n;
	
	right = 0;
	memset(num, 0, sizeof(num));
	FOR(i, 1, n) {
		cin >> vote[i].fi >> vote[i].se;//fi is number of candidate, se is the price
		num[vote[i].fi]++;
		right = max(right, vote[i].fi);
	}
	
	sort(vote+1, vote+1+n, cmp);
	
	//ternary search
	left = 1;
	right++;
	FOR(i, 0, 100) {
		long x1 = left + (right-left)/3;
		long x2 = right - (right-left)/3;
		
		if (f(x1)<f(x2)) right = x2;
		else left = x1;
	}
	
	cout << f(left);
	return 0;
}
