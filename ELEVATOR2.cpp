#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxk 400+10

using namespace std;

struct node {
	long h, a, c;
	
	bool operator<(const node&p) {
		return (a<p.a);
	}
};

long k;
node rock[maxk];
set<long> Set;
vector<long> v;

long min(long a, long b){
	if (a<=b) return a;
	return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k;
	FOR(i, 1, k) cin >> rock[i].h >> rock[i].a >> rock[i].c;
	sort(rock+1, rock+1+k);
	
	Set.insert(0);
	
	FOR(i, 1, k) {
		if (rock[i].h>rock[i].a) continue;
		v.clear();
		for (auto iter = Set.begin(); iter!=Set.end(); iter++) {
			FOR(j, 1, rock[i].c) 
				if (*iter+rock[i].h*j<=rock[i].a) v.push_back(*iter+rock[i].h*j);
				else break;
		}
		for(auto iter = v.begin(); iter!=v.end(); iter++) Set.insert(*iter);
	}
	
	set<long>::reverse_iterator riter = Set.rbegin();
	cout << *riter;
	return 0;
}
