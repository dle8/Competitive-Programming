#include <bits/stdc++.h>
#include <string>
#include <sstream>
#define maxn 50000+10
using namespace std;
int n;
int a[maxn];
 
class stk {
	public: 
		int elem[maxn];
		int first, top;
	
	void init() {
		first = 1;
		top = 0;
	}
	
	bool empty() {
		return (first>top);
	}
	
	int peek() {
		return(elem[top]);
	}
	
	void add(int x) {
		top++;
		elem[top] = x;
	}
	
	void pop() {
		top--;
	}
};
 
string solve() {
	stk stackMin, stackMax;
	stackMin.init();
	stackMax.init();
	if (n==1) return "YES";
	for (int i=2; i<=n; i++) {
		if (a[i]<a[i-1]) { // giam
			if (!stackMax.empty() && a[i]<stackMax.peek()) return "NO";
			if (!stackMax.empty() && a[i]==stackMax.peek()) stackMax.pop();
			stackMin.add(a[i-1]);
		}
		if (a[i]>a[i-1]) {//tang
			if (!stackMin.empty() && a[i]>stackMin.peek()) return "NO";
			if (!stackMin.empty() && a[i]==stackMin.peek()) stackMin.pop();
			stackMax.add(a[i-1]);
		}
	}
	return "YES";
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string inp;
	n = 0;
	while (getline(cin, inp)) {
		stringstream ss(inp);
		string token;
		while (getline(ss, token, ' ')) {
			n++;
			a[n] = stoi(token);
		}
	}
	cout << solve();
	return 0;
} 
