#include <bits/stdc++.h>
#define maxn 1000+10
using namespace std;

int n, k;

class normalQueue {
	public:
		int q[maxn];
		int first, last;

	void init() {
		first = 1;
		last = 0;
	}
	
	bool empty() {
		return (first>last);
	}
	
	void add(int p) {
		last++;
		q[last] = p;
	}	
	
	int peek() {
		return q[first];
	}
	
	void poll() {
		first++;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int u, res;
	cin >> n >> k;
	normalQueue q;
	q.init();
	q.add(n);
	while (!q.empty()) {
		u = q.peek();
		q.poll();
		if (u>k && ((u-k)%2==0)) {
			q.add((u-k)/2);
			q.add((u+k)/2);
		} else res++;
	}
	cout << res;
	return 0;
}
