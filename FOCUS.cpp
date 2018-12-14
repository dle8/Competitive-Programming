#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#define maxn 200000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define mp make_pair
using namespace std;

map<long, long> roirac;//dung roi rac hoa de thu nho cac gia tri
map<long, long> rroirac;//cong dung nguoc lai voi map roirac
long it[12*maxn], x[maxn], a[maxn], b[maxn], n, mang[3*maxn];

void update(long cs, long u, long v, long i, long val) {
	if (i<u || v<i) return;
	it[cs]+=val;
	if (u==v) return;
	long mid = (u+v)/2;
	update(2*cs, u, mid, i, val);
	update(2*cs+1, mid+1, v, i, val);
}

long getAge(long cs, long u, long v, long l, long r) {
	if (r<u || v<l) return 0;
	if (l<=u && v<=r) return it[cs];
	long mid = (u+v)/2;
	return getAge(2*cs, u, mid, l, r) + getAge(2*cs+1, mid+1, v, l, r);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long count, slbien, last, l, r, left, mid, k;
	char tcase[maxn];
	cin >> n;
	
	count = 0;
	FOR(i, 1, n) {
		cin >> tcase[i];
		cin >> x[i];
		if (tcase[i]=='+' || tcase[i]=='-') {
			count++;
			mang[count] = x[i];
			continue;
		}
		cin >> a[i] >> b[i];
		count++;
		mang[count] = a[i];
		count++;
		mang[count] = b[i];
	}
	
	sort(mang+1, mang+1+count);
	slbien = 0;
	last = 0;
	FOR(i, 1, count) {
		if (mang[i]!=last) {
			last = mang[i];
			slbien++;
			roirac.insert(mp(mang[i], slbien));
			rroirac.insert(mp(slbien, mang[i]));
		}
	}
	
	FOR(i, 1, n) {
		if (tcase[i]=='+') update(1, 1, slbien, roirac[x[i]], 1);
		else if (tcase[i]=='-') update(1, 1, slbien, roirac[x[i]], -1);
		else {
			l = roirac[a[i]];
			r = roirac[b[i]];
			k = x[i];
			if (getAge(1, 1, slbien, l, r)<k) {
				cout << 0 << "\n";
				continue;
			}
			while (l<=r) {
				mid = (l+r)/2;
				left = getAge(1, 1, slbien, l, mid);
				if (k>left) {
					k-=left;
					l = mid+1;
				}
				else r = mid-1;
			}
			cout << rroirac[l] << "\n";
		}
	}
	return 0;
}
