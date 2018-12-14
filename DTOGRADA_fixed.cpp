#include <iostream>
using namespace std;
int f[1000000+10], g[1000000+10], h[1000000+10], st[1000000+10];

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

int main() {
	int n, x, first, top, j, socayLan;
	unsigned int leftOverArea;
	
	cin >> n >> x;
	for (int i=1; i<=n; i++) cin >> h[i];
	
	top = 0;
	first = 1;
	for (int i=1; i<=min(x-1, n); i++) {
		while (top >= first && h[i] <= h[st[top]]) top--;
		top++;
		st[top] = i;
	}
	
	for (int i=x; i<=n; i++) {
		while (top >= first && h[i]<=h[st[top]]) top--;//stack min
		top++;
		st[top] = i;
		while (top >=first && (i-st[first]>=x)) first++;
		f[i] = h[st[first]];
	}
	
	top = 0;
	first = 1;
	for (int i=n; i>=1; i--) {
		while (top>=first && f[i]>=f[st[top]]) top--;//stack max
		top++;
		st[top] = i;
		while (top>=first && st[first]-i>=x) first++;
		g[i] = f[st[first]];
	}
	
//	for (int i=1; i<=n; i++) cout << g[i] <<  " ";
	
	for (int i=1; i<=n; i++) 
		leftOverArea = leftOverArea + h[i] - g[i];//g[i] la phan duoc to mau tren cot i
	
	socayLan = 0;
	int i = 1;
	while (i<=n) {
		if (g[i] == 0) i++;
		else {
			j = i+1;
			while (j<=min(i+x-1, n) && g[j] == g[i]) j++;
			socayLan++;
			i = j;
		}
	}
	
	cout << leftOverArea << endl;
	cout << socayLan;
	return 0;
}
