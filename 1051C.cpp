#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 100+10
using namespace std;

long n;
long s[maxn];
bool morethan3;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long count, totalCount;
	cin >> n;
	multiset<long> ms;
	FOR(i, 1, n) {
		cin >> s[i];
		ms.insert(s[i]);
	}
	
	totalCount = 0;
	morethan3 = false;
	FOR(i, 1, n) {
		if (ms.count(s[i])==1) totalCount++;
		if (ms.count(s[i])>=3) morethan3 = true;	
	}
	if (totalCount%2!=0 && !morethan3) return cout << "NO", 0;
	
	cout << "YES" << "\n";
	count = 0;
	FOR(i, 1, n) {
		if (ms.count(s[i])==1) {
			++count;
			if (count%2==0) cout << "A";
			else cout << "B";
		}
		else {
			if (totalCount%2!=0 && ms.count(s[i])>=3 && morethan3) {
				morethan3 = false;
				cout << "A";
			}
			else cout << "B";
		}
	}
	return 0;
}
