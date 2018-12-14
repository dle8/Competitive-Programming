#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 100000+10
#define pb push_back
using namespace std;

struct node {
	long duration, end, numth;
	
	bool operator<(const node &p) {
		return (end<p.end || (end==p.end && duration<p.duration));
	}
};

long n, col, f[maxn], trace[maxn];
node job[maxn];
list<long> order;
bool check[maxn];

long bs(long c, long key) {
	long d = 1;
	while (d<=c) {
		long mid = (d+c)/2;
		if (f[mid]<=key) d = mid+1;
		else c = mid-1;
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long index;
	cin >> n;
	FOR(i, 1, n) cin >> job[i].duration;
	FOR(i, 1, n) {
		cin >> job[i].end;
		job[i].numth = i;
	}
	
	sort(job+1, job+1+n);
//	FOR(i, 1, n) cout << job[i].duration << " " << job[i].end << endl;	
	col = 0;
	if (job[1].duration<=job[1].end) {
		col++;
		f[1] = job[1].duration;
		trace[1] = job[1].numth;
	}
	FOR(i, 2, n) {
		if (job[i].duration>job[i].end) continue;
		index = bs(col, job[i].end-job[i].duration);//tim thg sap dc nhieu lich dung han nhat co tgian ket thuc <= tgian bat dau cua cong viec i
//		cout << index << " " << col << endl;
		if (index==col) {
			col++;
			f[col] = f[col-1]+job[i].duration;
			trace[col] = job[i].numth;
		}
		if (f[index+1]>f[index]+job[i].duration) {
			f[index+1] = f[index]+job[i].duration;
			trace[index+1] = job[i].numth;
		}	
	}
	
	memset(check, false, sizeof(check));
	cout << n-col << "\n";
	FOR(i, 1, col) {
		order.pb(trace[i]);
		check[trace[i]] = true;
	}
	
	FOR(i, 1, n)
		if (!check[i]) {
			check[i] = true;
			order.pb(i);
		}
		
	for (list<long>::iterator iter = order.begin(); iter!=order.end(); iter++) cout << *iter << " ";
	
	return 0;
}
