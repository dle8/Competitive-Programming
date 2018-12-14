#include <bits/stdc++.h>
#define maxn 50000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

struct node {
	long count, end;
	node* c[2];
};

class Trie {
	public:
		node* root;
	
	Trie() {
		add(root);
	}
	
	void add(node* &p) {
		p = new node;
		p->count = 0;
		p->end = 0;
		FOR(i, 0, 1) p->c[i] = nullptr;
	}
	
	void insert(string s) {
		long lengths = s.length();
		node* p = root;
		FOR(i, 0, lengths-1) {
			if (p->c[(int)(s[i]-'0')]==nullptr) add(p->c[(int)(s[i]-'0')]);
			p = p->c[(int)(s[i]-'0')];
			p->count++;
		}
		p->end++;
	}
	
	long findDecoded(string s) {
		long lengths = s.length();
		long count = 0;
		node* p = root;
		FOR(i, 0, lengths-1) {
			if (p->end!=0) count+=p->end;
			if (p->c[(int)(s[i]-'0')]==nullptr) add(p->c[(int)(s[i]-'0')]);
			p = p->c[(int)(s[i]-'0')];
		}
		return p->count + count;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long m, n, k;
	string mess;
	char ch;
	Trie trie;
	cin >> m >> n;
	FOR(i, 1, m) {
		cin >> k;
		mess = "";
		FOR(j, 1, k){
			cin >> ch;
			mess+=ch;
		}
		trie.insert(mess);
	}
	
	FOR(i, 1, n) {
		cin >> k;
		mess = "";
		FOR(j, 1, k) {
			cin >> ch;
			mess+=ch;
		}
		cout << trie.findDecoded(mess) << "\n";
	}
	return 0;
}
