#include <iostream>
#include <queue>
#define maxn 100+10
#define mp make_pair
#define f first
#define s second
#define maxc 1000000000
using namespace std;

typedef pair<long, long> pll;

long a[maxn][maxn], denx[maxn], deny[maxn], soden, tx[maxn][maxn], ty[maxn][maxn], m, n;
queue<pll> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long blue, red, x, y, temp;
	string s;
	cin >> m >> n;
	for (int i=1; i<=m; i++){
		cin >> s;
		for (int j=1; j<=n; j++)
		if (s[j-1]=='1') {
			q.push(mp(i, j));
			denx[i]++;
			deny[j]++;
		}
	}
	
	soden = -maxc;
	for (int i=1; i<=m; i++) 
		if (soden<denx[i]) soden = denx[i];
	for (int i=1; i<=n; i++)
		if (soden<deny[i]) soden = deny[i];
		
	cout << soden << "\n";
	
	while (!q.empty()) {
		x = q.front().f;
		y = q.front().s;
		q.pop();
		blue = -1;
		red = -1;
		for (int c=1; c<=soden; c++) 
		if (tx[x][c]==0) {
			blue = c;
			break;
		}
		for (int c=1; c<=soden; c++) 
		if (ty[y][c]==0 && c!=blue) {
			red = c;
			break;
		}
		while (true) {
			a[x][y] = blue;
			tx[x][blue] = y;
			temp = ty[y][blue];
			ty[y][blue] = x;//tuc la cot nay da co blue
			tx[temp][blue] = 0;
			if (temp==0) break;
			x = temp;
			
			a[x][y] = red;
			ty[y][red] = x;
			temp = tx[x][red];
			tx[x][red] = y;//neu hang nay da co red
			ty[temp][red] = 0;
			if (temp==0) break;
			y = temp;
		}
	}
	
	for (int i=1; i<=m; i++){
		for (int j=1; j<=n; j++) cout << a[i][j]<< " ";
		cout << "\n";	
	}
	return 0;
}
