#include <iostream>
#define maxn 25000+100
using namespace std;

int n;
long long dist[maxn], f[maxn];

long long min(long long a, long long b) {
	if (a<=b) return a;
	else return b;
}

int main() {
	cin >> n;
	for (int i=1; i<=n-1; i++) cin >> dist[i];//dist[i] la khoang cach giua noi may i voi may i+1
	f[1] = 0;
	f[2] = dist[1];
	f[3] = dist[1] + dist[2];
	for (int i=4; i<=n; i++) 
		f[i] = min(f[i-2], f[i-1])+dist[i-1];
	cout << f[n];
	return 0;
}
