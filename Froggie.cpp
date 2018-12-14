/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

#define maxn 100+10

bool noEnter[maxn][maxn][maxn];
string path;
long lengthPath, l, w;

bool tryOut(long j) {
	long i = 0;
	long time = 0;
	long numU = 0;
	FOR(t, 0, lengthPath-1) {
		if (path[t] == 'L') j--;
		if (path[t] == 'R') j++;
		if (path[t] == 'D') i--;
		if (path[t] == 'U') {
			i++; 
			numU++;
		}
		time++;
		if (noEnter[i][j][time]) return false;
	}
	
	//ktra so U
	if (numU <= l) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long first, interval, speed;
	cin >> l >> w;
	memset(noEnter, false, sizeof(noEnter));
	FOR(i, 1, l) {
		cin >> first >> interval >> speed;
		//luc dau co thang dung o first, cu cach moi interval lai co 1 thang, 
		//xet cho tung thang o cho interval 
		FOR(t, 0, 100) {
			FOR(j, 0, 100) if (first + j*interval <= w) noEnter[i][first + j*interval][t] = true;
			first+=speed;
			long tmp = first;
			while (tmp - interval>0) {
				tmp-=interval;
				noEnter[i][tmp][t] = true;
			}
			
		} 
	}
	
	cin >> path;
	lengthPath = path.length();
	
	FOR(i, 0, w) {
		if (tryOut(i)) return cout << "safe", 0;
	}
	
	cout << "squish";
	
	return 0;
}
