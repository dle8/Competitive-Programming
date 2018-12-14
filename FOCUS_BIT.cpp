#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 200000+10
#define mp make_pair
using namespace std;

long ft[maxn], a[maxn], b[maxn], x[maxn], mang[3*maxn], n, slbien;
map<long, long> roirac, rroirac;

void update(long i, long val) {
	for (; i<=slbien; i+=(i&(-i))) ft[i]+=val;
}

long getAge(long i) {
	long sum = 0;
	for (; i>0; i-=(i&(-i))) sum+=ft[i];
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long count, last, l, r, left, mid, k;
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
		if (tcase[i]=='+') update(roirac[x[i]], 1);
		else if (tcase[i]=='-') update(roirac[x[i]], -1);
		else {
			l = roirac[a[i]];
			r = roirac[b[i]];
			k = x[i];
			if (getAge(r)-getAge(l-1)<k) {
				cout << 0 << "\n";
				continue;
			}
			while (l<=r) {
				mid = (l+r)/2;
				left = getAge(mid)-getAge(l-1);
				if (k>left) {//dau = o day la sai
					k = k-left;
					l = mid+1;
				} else r = mid-1;
			}
			cout << rroirac[l] << "\n";
		}
	}
	return 0;
}
