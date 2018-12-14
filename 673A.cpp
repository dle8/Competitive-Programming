#include <bits/stdc++.h>
#define maxn 90+10
using namespace std;

long n, count;
bool check[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long interesting, count , res;
	cin >> n;
	memset(check, false, sizeof(check));
	for (int i=1; i<=n; i++) {
		cin >> interesting;
		check[interesting] = true;
	}
	
	res = 0;
	count = 0;
	for (int i=1; i<=90; i++) {
		if (check[i]) count = 0;
		else count++;
		res++;
		if (count==15) break;
	}
	
	cout << res;
	return 0;
}
