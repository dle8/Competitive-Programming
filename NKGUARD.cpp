#include <bits/stdc++.h>
#include <utility>
#include <queue>
#define maxn 700+10
using namespace std;
 
int n, m, result;
bool check[maxn][maxn], inQueue[maxn][maxn];
pair<int, int> vungdoi[maxn];
int h[maxn][maxn];
 
bool satisfy(int i, int j) {
	if (
		h[i-1][j]>h[i][j] || 
		h[i+1][j]>h[i][j] || 
		h[i][j+1]>h[i][j] || 
		h[i][j-1]>h[i][j] || 
		h[i-1][j-1]>h[i][j] ||
		h[i-1][j+1]>h[i][j] ||
		h[i+1][j-1]>h[i][j] || 
		h[i+1][j+1]>h[i][j]
	) return false;
	return true;
}
 
void bfs(int i, int j) {
	int dem;
	queue<pair<int, int>> q;
	pair<int, int> u;
	u = make_pair(i, j);
	q.push(u);
	dem = 0;
	inQueue[u.first][u.second] = false;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		if (!satisfy(u.first, u.second)) {
			inQueue[i][j] = true;
			for (int k=1; k<=dem; k++)
				inQueue[vungdoi[k].first][vungdoi[k].second] = true;
			return;	
		}
		
		if (inQueue[u.first-1][u.second] && h[u.first-1][u.second]==h[u.first][u.second]) {
			dem++;
			vungdoi[dem] = make_pair(u.first-1, u.second);
			q.push(vungdoi[dem]);
			inQueue[u.first-1][u.second] = false;
		}
		if (inQueue[u.first+1][u.second] && h[u.first+1][u.second]==h[u.first][u.second]) {
			dem++;
			vungdoi[dem] = make_pair(u.first+1, u.second);
			q.push(vungdoi[dem]);
			inQueue[u.first+1][u.second] = false;
		}
		if (inQueue[u.first][u.second-1] && h[u.first][u.second-1]==h[u.first][u.second]) {
			dem++;
			vungdoi[dem] = make_pair(u.first, u.second-1);
			q.push(vungdoi[dem]);
			inQueue[u.first][u.second-1] = false;
		}
		if (inQueue[u.first][u.second+1] && h[u.first][u.second+1]==h[u.first][u.second]) {
			dem++;
			vungdoi[dem] = make_pair(u.first, u.second+1);
			q.push(vungdoi[dem]);
			inQueue[u.first][u.second+1] = false;
		}
		if (inQueue[u.first-1][u.second-1] && h[u.first-1][u.second-1]==h[u.first][u.second]) {
			dem++;
			vungdoi[dem] = make_pair(u.first-1, u.second-1);
			q.push(vungdoi[dem]);
			inQueue[u.first-1][u.second-1] = false;
		}
		if (inQueue[u.first-1][u.second+1] && h[u.first-1][u.second+1]==h[u.first][u.second]) {
			dem++;
			vungdoi[dem] = make_pair(u.first-1, u.second+1);
			q.push(vungdoi[dem]);
			inQueue[u.first-1][u.second+1] = false;
		}
		if (inQueue[u.first+1][u.second-1] && h[u.first+1][u.second-1]==h[u.first][u.second]) {
			dem++;
			vungdoi[dem] = make_pair(u.first+1, u.second-1);
			q.push(vungdoi[dem]);
			inQueue[u.first+1][u.second-1] = false;
		}
		if (inQueue[u.first+1][u.second+1] && h[u.first+1][u.second+1]==h[u.first][u.second]) {
			dem++;
			vungdoi[dem] = make_pair(u.first+1, u.second+1);
			q.push(vungdoi[dem]);
			inQueue[u.first+1][u.second+1] = false;
		}
	}
	result++;
//	cout << i << " " << j << endl;
	check[i][j] = false;
	inQueue[i][j] = true;
	for (int k=1; k<=dem; k++) {
		check[vungdoi[k].first][vungdoi[k].second] = false;
		inQueue[vungdoi[k].first][vungdoi[k].second] = true;	
	}
	
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		memset(check[i], true, sizeof(check[i]));
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=m; j++) 
			cin >> h[i][j];	
	
	for (int i=0; i<=(n+1); i++) {
		h[i][0] = -1;
		h[i][m+1] = -1;
	}
	
	for (int j=0; j<=(m+1); j++) {
		h[0][j] = -1;
		h[n+1][j] = -1;
	}
 
	result = 0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) inQueue[i][j] = true;
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++) {
			if (check[i][j]) bfs(i,j);
		}
	}
	
	cout << result;
	return 0;
}  
