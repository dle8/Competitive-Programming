#include <bits/stdc++.h>
#define maxn 10000+10
using namespace std;

struct node {
	long a, b, index;
	
	bool operator<(const node&p) {
		return (a*p.b>p.a*b);
	}
};

node arr[maxn];

long n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long cost;
	long days;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> arr[i].a;
		arr[i].index = i;	
	} 
	for (int i=1; i<=n; i++) cin >> arr[i].b;
	sort(arr+1, arr+1+n);
	days = 0;
	cost = 0;
	for (int i=1; i<=n; i++) {
		days+=arr[i].b;
		cost+=(arr[i].a*days);
	}
	cout << cost << endl;
	for (int i=1; i<=n; i++) cout << arr[i].index << " " ;
	return 0;
}
