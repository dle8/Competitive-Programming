#include <bits/stdc++.h>
#define maxn 30+10
using namespace std;

long long f[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	f[0] = 1;
	f[2] = 3;
	for (int i=4; i<=30; i=i+2) 
		f[i] = 4*f[i-2]-f[i-4];
	
	while (true) {
		cin >> n;
		if (n==-1) break;
		if (n%2!=0) cout << 0 << endl;
		else cout << f[n] << endl;
	}
	return 0;
}
