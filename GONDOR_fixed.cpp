#include <bits/stdc++.h>
#define maxn 100+10
using namespace std;

int n;
int x[maxn], y[maxn], s[maxn];
double d[maxn];
bool check[maxn];
int tower[maxn][maxn];

int min(int a, int b) {
	if (a<=b) return a;
	else return  b;
}

double dist(int i, int j) {
	return(sqrt((x[i]-x[j])*(x[i]-x[j])+ (y[i]-y[j])*(y[i]-y[j])));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int index, dem;
	double minVal;
	bool stop;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> x[i] >> y[i];
		cin >> s[i];
		for (int j=1; j<=(n-1); j++) cin >> tower[i][j];
	}
	
	memset(check, true, sizeof(check));
	for (int i=1; i<=n; i++) d[i] = 1000000000;
	d[1] = 0;
	while (true) {
		stop = true;
		minVal = 1000000000;
		for (int i=1; i<=n; i++) {
			if (d[i]<minVal && check[i]) {
				minVal = d[i];
				index = i;
				stop = false;
			}
		}
	
		if (stop) break;
		check[index] = false;
		dem = 0;
		for (int j=1; j<=(n-1); j++) {
			if (dem<s[index] && check[tower[index][j]]) {
				dem++;
				d[tower[index][j]] = min(d[tower[index][j]], d[index]+dist(index, tower[index][j]));
			}
		}
	}
	
	for (int i=1; i<=n; i++) cout << d[i] << endl;
	
	return 0;
}
