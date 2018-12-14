#include <bits/stdc++.h>
#define FORU(i, l, r) for (int i=l; i<=r; i++)
#define FORD(i, l, r) for (int i=l; i>=r; i--)
#define maxn 1000000+10
#define maxa 10000+10
#define oo 1000000000
#define eps 1e-9
using namespace std;

long tcount[maxa], mang[maxa], a[maxn];
set<long> Set;
set<long>::iterator it;

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long side1, side2, tcase, n, index, num, res;
	double min;
	bool stop;
	cin >> tcase;
	FORU(o, 1, tcase) {
		cin >> n;
		memset(tcount, 0, sizeof(tcount));
		stop = false;
		res = 0;
		Set.clear();
		FORU(i, 1, n) {
			cin >> a[i];
			tcount[a[i]]++;
			if (tcount[a[i]]>=4) {
				res = a[i];
				stop = true;
			}
			else if (tcount[a[i]]>=2) Set.insert(a[i]);	
		}
		
		if (stop) {
			cout << res << " " << res << " " << res << " " << res << endl;
			continue;
		}

		index = 0;
		for (it=Set.begin(); it!=Set.end(); ++it) {
			index++;
			mang[index] = *it;
		}
		sort(mang+1, mang+1+index);
		
		side1 = 0;
		side2 = 0;
		min = oo;
		FORU(i, 2, index) {
			if (((mang[i]/double(mang[i-1])+mang[i-1]/double(mang[i]))-min)<eps) {
				min = mang[i]/double(mang[i-1])+mang[i-1]/double(mang[i]);
				side1 = mang[i];
				side2 = mang[i-1];
			}
		}
		
		cout << side1 << " " << side1 << " " << side2 << " " << side2 << "\n";
	}
	return 0;
}
