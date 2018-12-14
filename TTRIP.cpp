#include <iostream>
#include <string.h>
#include <algorithm>
#include <set>
#define maxc 1000000000
#define maxn 100+10
using namespace std;

long a[maxn][maxn], n;
bool check[maxn];

void floyd() {
	for (int k=1; k<=n; k++)
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++) 
		if (a[i][j]>a[i][k]+a[k][j]) a[i][j] = a[i][k]+a[k][j];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long s, res, temp;
	cin >> n;
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++) {
		cin >> a[i][j];
		if (a[i][j]==0) a[i][j] = maxc;
	} 

	floyd();
	memset(check, true, sizeof(check));
	s = 1;
	check[s] = false;
	res = 0;
	while (true) {
		long min = maxc;
		bool flag = true;
		for (int i=2; i<=(n-1); i++) {
			if (a[s][i]!=maxc && check[i] && a[s][i]<min) {
				min = a[s][i];
				temp = i;
				flag = false;
			}
		}
		if (flag) temp = n;
		check[temp] = false;
//		cout << s << " " << temp << " " << a[s][temp] << "\n";
		res+=a[s][temp];
		s = temp;
		if (s==n) break;
	}
	
	cout << res;
	
	return 0;
}
