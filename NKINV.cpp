#include <iostream>
#define maxn 60000+10
using namespace std;
int n;
int a[maxn], it[4*maxn];

int max(int a, int b) {
	if (a>=b) return a;
	else return b;
}

void update(int cs, int u, int v, int i) {
	if (u==i && v==i) it[cs]++;
	else {
		int g = (u+v)/2;
		if (i<=g) {
			it[cs] = it[cs] - it[2*cs];
			update(2*cs, u, g, i);
			it[cs] = it[cs] + it[2*cs];
		} else {
			it[cs] = it[cs] - it[2*cs+1];
			update(2*cs+1, g+1, v, i);
			it[cs] = it[cs] + it[2*cs+1];
		}
	}
}

int itSum(int cs, int u, int v, int x, int y) {
	if (u==x && v==y) return it[cs];
	else {
		int g = (u+v)/2;
		if (y<=g) return itSum(2*cs, u, g, x, y);
		if (x>=g+1) return itSum(2*cs+1, g+1, v, x, y);
		else return (itSum(2*cs, u, g, x, g) + itSum(2*cs+1, g+1, v, g+1, y));
	}
}
 
int main() {
	int nghichthe, temp;
	cin >> n;
	int maxA_i = -1000000000;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		maxA_i = max(maxA_i, a[i]);
	} 
	
	nghichthe = 0;
	
	for (int i=n; i>=1; i--) {
		if (a[i]>1) {
			temp = itSum(1, 1, maxA_i, 1, a[i]-1);
			nghichthe+=temp;
		}
		update(1, 1, maxA_i, a[i]);
	}
	
	cout << nghichthe;
}
