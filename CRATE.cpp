#include <bits/stdc++.h>
#define maxn 300000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;
 
struct nlll {
	long a, h, pos;
};
 
struct pnode {
	long v;
	pnode* next;
};
 
struct nll {
	long h, pos;
};
 
nlll coder[maxn], diffcoder[maxn];
long n, tcount, ft[maxn], res[maxn], vt[maxn], sl[maxn];
pnode* head[maxn];
nll sh[maxn];
 
bool smallera(const nlll&x, const nlll&y) {
	return ((x.a<y.a) || (x.a==y.a && x.h<y.h));
}
 
bool smallerh(const nll&x, const nll&y) {
	return (x.h<y.h);
}
 
void update(long i, long val) {
	for(; i<=tcount; i+=(i&(-i))) ft[i]+=val;
}
 
long getSum(long i) {
	long sum = 0;
	for(; i>0; i-=(i&(-i))) sum+=ft[i];
	return sum;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pnode* p;
	cin >> n;
	FOR(i, 1, n) {
		cin >> coder[i].a >> coder[i].h;
		coder[i].pos = i;
	}
	
	sort(coder+1, coder+1+n, smallera);//sort tang theo a
	
	tcount = 1;
	coder[n+1].a = -1;
	coder[n+1].h = -1;
	FOR(i, 2, n+1) {
		sl[tcount]++;
		p = new pnode;
		p->v = i-1;
		p->next = head[tcount];
		head[tcount] = p;
		if (coder[i].a!=coder[i-1].a || coder[i].h!=coder[i-1].h) {
			diffcoder[tcount].a = coder[i-1].a;
//			diffcoder[tcount].h = coder[i-1].h;
			
			sh[tcount].h = coder[i-1].h;
			sh[tcount].pos = tcount;
			tcount++;	
		}
	}
	
	tcount--;
	sort(sh+1, sh+1+tcount, smallerh);//sort tang dan theo h
 
	FOR(i, 1, tcount) vt[sh[i].pos] = i;
	
	FOR(i, 2, tcount) {
		update(vt[i-1], sl[i-1]);
		long temp = getSum(vt[i]-1);
		
		p = head[i];
		while (p!=nullptr) {
			res[coder[p->v].pos] = temp;
			p = p->next;
		}
	}	
	
	FOR(i, 1, n) cout << res[i] << "\n";
	return 0;
}
