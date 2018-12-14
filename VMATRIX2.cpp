#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 1000+10
#define mod 10
#define testTimes 6
using namespace std;
 
long n;
long a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], frei[maxn][2], sub1[maxn][2], sub2[maxn][2], sub3[maxn][2];
 
void freivalds() {
	srand(time(NULL));
	FOR(i, 1, n) frei[i][1] = rand()%2;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string input;
	long test;
	cin >> test;
	FOR(o, 1, test) {
		cin >> n;
		FOR(i, 1, n) {
			cin >> input;
			FOR(j, 1, n) a[i][j] = input[j-1]-48;
		}
		
		FOR(i, 1, n) {
			cin >> input;
			FOR(j, 1, n) b[i][j] = input[j-1]-48;
		}
		
		FOR(i, 1, n) {
			cin >> input;
			FOR(j, 1, n) c[i][j] = input[j-1]-48;
		}
		
		bool equal = true;
		FOR(idx, 1, testTimes) {
			memset(sub1, 0, sizeof(sub1));
			memset(sub2, 0, sizeof(sub2));
			memset(sub3, 0, sizeof(sub3));
			memset(frei, 0, sizeof(frei));
			if (!equal) break;
			
			for (int i=idx; i<=n; i+=2) frei[i][1] = 1;			
			//sub1 = b*frei;
			FOR(i, 1, n)
			FOR(j, 1, n) 
				sub1[i][1] = (sub1[i][1] + b[i][j]*frei[j][1])%mod;
			
			//sub2 = a*sub1;
			FOR(i, 1, n)
			FOR(j, 1, n) 
				sub2[i][1] = (sub2[i][1] + a[i][j]*sub1[j][1])%mod;
			
			//sub1 = c*frei;
			FOR(i, 1, n)
			FOR(j, 1, n) 
				sub3[i][1] = (sub3[i][1] + c[i][j]*frei[j][1])%mod;
			
			//check if the two matrix is the same.
			FOR(i, 1, n) 
			if (sub3[i][1]!=sub2[i][1]) equal = false;
		}
		
		if (equal) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
} 
