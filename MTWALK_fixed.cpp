#include <bits/stdc++.h>
#define maxn 100+10
using namespace std;

long n;
bool check[maxn][maxn];
long h[maxn][maxn];
long di[5],dj[5];

void init() {
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++) check[i][j]=true;
	
	for (int i=0; i<=n+1; i++) {
		check[i][0] = false;
		check[i][n+1] = false;
		check[0][i] = false;
		check[n+1][i] = false;
	}
}

bool dfs(int i, int j, int lower, int upper) {
	if (i==n && j==n) return true;
	check[i][j] = false;
	for (int k=1; k<=4; k++) {
		if (check[i+di[k]][j+dj[k]] && h[i+di[k]][j+dj[k]]>=lower && h[i+di[k]][j+dj[k]]<=upper) 
		if (dfs(i+di[k], j+dj[k], lower, upper)) return true;
	}
	return false;
}

void process() {
	int mid, lower, upper, l, r;
	di[1]=0;
	dj[1]=1;
	di[2]=0;
	dj[2]=-1;
	di[3]=1;
	dj[3]=0;
	di[4]=-1;
	dj[4]=0;
	l = 0;
	r = 110;
	//chat nhi phan theo ket qua bai lam
	while (l<=r) {
		int mid = (l+r)/2;
		bool found = false;
		for (lower=0; lower<=(110-mid); lower++) {
			upper = lower + mid;
			init();
			if (lower<=h[1][1] && h[1][1]<=upper)
				if (dfs(1, 1, lower, upper)) {
					found = true;
					break;
				}
		}
		if (found) r = mid-1;
		else l = mid+1;
	}
	cout << l;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++) cin >> h[i][j];
	
	process();	
	return 0;
}
