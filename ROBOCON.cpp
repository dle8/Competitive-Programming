#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define maxn 500+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

typedef pair<long, long> pll;

queue<pll> robo1, robo2;
bool goneRobo1[maxn][maxn], goneRobo2[maxn][maxn], obstacle[maxn][maxn];
long ttime[maxn][maxn], n;

long process() {
	pll u;
	FOR(i, 1, n)
	FOR(j, 1, n) {
		goneRobo1[i][j] = false;
		goneRobo2[i][j] = false;
		ttime[i][j] = 0;
	}
	robo1.push(mp(1, 1));
	robo2.push(mp(1, n));
	goneRobo1[1][1] = true;
	goneRobo2[1][n] = true;
	ttime[1][0] = 0;
	ttime[1][n] = 0;
	while (true) {
		u = robo1.front();
		robo1.pop();
		
		if (u.se<n && !obstacle[u.fi][u.se+1] && !goneRobo1[u.fi][u.se+1]) {
			if (goneRobo2[u.fi][u.se+1]) return cout << ttime[u.fi][u.se]+1, 0;
			else {
				goneRobo1[u.fi][u.se+1] = true;
				ttime[u.fi][u.se+1] = ttime[u.fi][u.se]+1;
				robo1.push(mp(u.fi, u.se+1));
			}	
		}
		
		if (u.fi<n && !obstacle[u.fi+1][u.se] && !goneRobo1[u.fi+1][u.se]) {
			if (goneRobo2[u.fi+1][u.se]) return cout << ttime[u.fi][u.se]+1, 0;
			else {
				goneRobo1[u.fi+1][u.se] = true;
				ttime[u.fi+1][u.se] = ttime[u.fi][u.se]+1;
				robo1.push(mp(u.fi+1, u.se));
			}	
		}
		
		if (u.fi<n && u.se<n && !obstacle[u.fi+1][u.se+1] &&!goneRobo1[u.fi+1][u.se+1]) {
			if (goneRobo2[u.fi+1][u.se+1]) return cout << ttime[u.fi][u.se]+1, 0;
			else {
				goneRobo1[u.fi+1][u.se+1] = true;
				ttime[u.fi+1][u.se+1] = ttime[u.fi][u.se]+1;
				robo1.push(mp(u.fi+1, u.se+1));
			}	
		}
		
		u = robo2.front();
		robo2.pop();
		
		if (u.se>1 && !obstacle[u.fi][u.se-1] && !goneRobo2[u.fi][u.se-1]) {
			if (goneRobo1[u.fi][u.se-1]) return cout << ttime[u.fi][u.se]+1, 0;
			else {
				goneRobo2[u.fi][u.se-1] = true;
				ttime[u.fi][u.se-1] = ttime[u.fi][u.se]+1;
				robo2.push(mp(u.fi, u.se-1));
			}
		}
		
		if (u.se>1 && u.fi<n && !obstacle[u.fi+1][u.se-1] && !goneRobo2[u.fi+1][u.se-1]) {
			if (goneRobo1[u.fi+1][u.se-1]) return cout << ttime[u.fi][u.se]+1, 0;
			else {	
				goneRobo2[u.fi+1][u.se-1] = true;
				ttime[u.fi+1][u.se-1] = ttime[u.fi][u.se]+1;
				robo2.push(mp(u.fi+1, u.se-1));
			}
		}
		
		if (u.fi<n && !obstacle[u.fi+1][u.se] && !goneRobo2[u.fi+1][u.se]) {
			if (goneRobo1[u.fi+1][u.se]) return cout << ttime[u.fi][u.se]+1, 0;
			else {
				goneRobo2[u.fi+1][u.se] = true;
				ttime[u.fi+1][u.se] = ttime[u.fi][u.se]+1;
				robo2.push(mp(u.fi+1, u.se));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long k, u, v;
	cin >> n >> k;
	FOR(i, 1, n)
	FOR(j, 1, n) obstacle[i][j] = false;
	FOR(i, 1, k) {
		cin >> u >> v;
		obstacle[u][v] = true;
	}
	
	process();
	return 0;
}
