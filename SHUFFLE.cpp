#include <bits/stdc++.h>
#define maxn 100000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

struct nlll {
	long i, j, m;
};

struct node {
	long val;
	node* next, prev;
};

nlll s[maxn];
node* head[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long count, n, k, x;
	cin >> n >> k >> x;

	node* p[maxn];
	p[0] = new node;
	p[n+1] = new node;
	FOR(i, 1, n+1) {
		p[i] = new node;
		p[i-1]->next = p[i];//co can them thg last sau thg n khong?	
		p[i].prev = p[i-1];			
	}

	long sqrtn = long(sqrt(n));

	FOR(i, 0, sqrtn) head[i] = p[i*sqrtn];

	node* d, c, shuff;
	
	FOR(i, 1, x) {
		cin >> s[i].i >> s[i].m >> s[i].j;
		long k = s[i].i/sqrtn;
		d = head[k];
		long index = k*sqrtn;
		while (index<s[i].i) {
			index++;
			d = d->next;
		}
		
		c = d;
		while (index<s[i].i+m-1) {
			index++;
			c = c->next;
		}

		if (s[i].j<=s[i].i-1) ind = s[i].i-1;
		else ind = s[i].j + s[i].m;
				
		k = ind/sqrtn;
		shuff = head[k];
		index = k*sqrtn;
		while (index<ind-1) {
			index++;
			shuff = shuff->next;
		}
		
		d->prev->next = shuff->prev;
		shuff->prev->next = d;
		d->prev = shuff->prev;
		shuff->prev = c;
		c->next = shuff;
	}
	
	delete p[];	
	return 0;
}
