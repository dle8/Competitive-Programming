#include <bits/stdc++.h>
#include <string.h>
#define maxn 1000+10
using namespace std;
 
int m, n;
int stackMin[maxn], h[maxn], nextRight[maxn], nextLeft[maxn], a[maxn*maxn];
 
int max(int a, int b) {
	if (a>=b) return a;
	else return b;
}
 
void process() {
	
	long top, res, index;
	
	res = 0;
	
	for (int i=1; i<=m; i++) {
		top = 0;
		memset(nextRight, 0, sizeof(nextRight));
		memset(nextLeft, 0, sizeof(nextLeft));
		for (int j=1; j<=n; j++) {
			index = (i-1)*n+j;
			if (a[index]==0) h[j] = 0;
			else h[j]++;
		}
		for (int j=1; j<=n; j++) {
			while (top>0 && h[stackMin[top]]>h[j]) {
				nextRight[stackMin[top]] = j-1;
				top--;
			}
			top++;
			stackMin[top] = j;	
		}
		while (top>0) {
			nextRight[stackMin[top]] = n;
			top--;
		}
		
		for (int j=n; j>=1; j--) {
			while (top>0 && h[stackMin[top]]>h[j]) {
				nextLeft[stackMin[top]] = j+1;
				top--;
			}
			top++;
			stackMin[top] = j;
		}
		while (top>0) {
			nextLeft[stackMin[top]] = 1;
			top--;
		}
		
		for (int j=1; j<=n; j++) 
		if (h[j]!=0) res = max(res, h[j]*(nextRight[j]-nextLeft[j]+1));
	}
	cout << res;
}
 
int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m>>n;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++) cin >> a[(i-1)*n+j];
	
	memset(h, 0, sizeof(h));
	process();
	return 0;
} 
