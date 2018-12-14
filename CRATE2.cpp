#include <bits/stdc++.h>
#define maxn 300000+10
#define FORU(i, l, r) for (long i=l; i<=r; i++)
#define FORD(i, r, l) for (long i=r; i>=l; i--)
using namespace std;

struct pts {
	long a, h, pos;
};

pts coder[maxn];
long num[maxn], res[maxn], n, ft[maxn];

bool smaller(const pts&x, const pts&y) {
	return ((x.a<y.a) || (x.a==y.a && x.h<y.h));
}

void update(long i, long val) {
	for(; i<=n; i+=(i&(-i))) ft[i]+=val;
}

long getSum(long i) {
	long sum = 0;
	for (; i>0; i-=(i&(-i))) sum+=ft[i];
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long sl;
	cin >> n;
	FORU(i, 1, n) {
		cin >> coder[i].a >> coder[i].h;
		coder[i].pos = i;	
	}
	
	sort(coder+1, coder+1+n, smaller);
	
	FORU(i, 1, n) cout << coder[i].a << " " << coder[i].h << "\n";
	sl = 0;
	coder[n+1].a = -1;
	coder[n+1].h = -1;
	FORU(i, 2, n+1) {
		sl++;
		if (coder[i].a!=coder[i-1].a || coder[i].h!=coder[i-1].h) {
			update(i-1, sl);
			res[i] = getSum(i-1);
			sl = 0;
		}
	}
	
	FORD(i, n-1, 1) 
		if (coder[i].a==coder[i+1].a && coder[i].h==coder[i+1].h) res[i] = res[i+1];
		
	FORU(i, 1, n) num[coder[i].pos] = res[i];
	FORU(i, 1, n) cout << num[i] << "\n";
	return 0;
}
