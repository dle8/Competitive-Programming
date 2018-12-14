#include <bits/stdc++.h>
#define maxn 300000+10
#define FORU(i, l, r) for (int i=l; i<=r; i++)
#define FORD(i, l, r) for (int i=l; i>=r; i--)
using namespace std;

bool check[maxn];
long p[maxn], n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	FORU(i, 1, n) cin >> p[i];
	cout << 1 << " ";
	memset(check, false, sizeof(check));
	long rightPlace = n+1;
	FORU(i, 1, n) {
		check[p[i]] = true;
		long temp = rightPlace;
		FORD(j, rightPlace-1, 1) 
		if (check[j]) temp = j;
		else {
			temp = j+1;
			break;	
		}
		rightPlace = temp;
		cout << i-n+rightPlace-1+1 << " ";		
	}
	return 0;
}
