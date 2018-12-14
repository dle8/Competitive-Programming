#include <bits/stdc++.h>
#include <string.h>
#define maxa 1000+10
using namespace std;

const int ntest = 10, minn = 3, maxn = 6;
int n;
int a[maxa][maxa];
bool check[maxn][maxn];

int main() {
	int u, v, k;
	srand(time(NULL));
	for (int itest = 1; itest<=ntest; itest++) {
		ofstream inp("nktrio.inp");
		n = minn + rand()%(maxn-minn+1);
		inp<< n << 	"\n";
		for (int i=1; i<=n; i++)
			memset(check, true, sizeof(check));
			
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (i==j) {
					a[i][j] = 0;
					check[i][j] = false;
				}
				if (check[i][j]) {
					a[i][j] = rand()%2;
					//check[i][j] = false;
					check[j][i] = false;
				} else if (i!=j) a[i][j] = 1-a[j][i];
			}
		}
		
		for (int i=1; i<=n;  i++) {
			for (int j=1; j<=n;  j++) {
				inp << a[i][j] << " ";
			}
			inp << "\n";
		}
		inp.close();
		system("NKTRIO.exe");
		freopen("nktrio.out", "r", stdin);
		cin >> u >> v >>k;
		cout << u <<" "<< v <<" " << k << endl;
		if ((a[u][v]==1 && a[v][k]==1 && a[k][u]==1) || (u==-1 && v==-1 && k==-1)) cout << "test " << itest << ":correct!\n";
		else cout << "test " << itest << ":wrong\n";
	}
	return 0;
}
