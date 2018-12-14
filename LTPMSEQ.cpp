#include <bits/stdc++.h>
#define maxn 100000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

struct node {
	long count;
	node* c[255];
};

map<string, long> Map;
string s[maxn];

class Trie {
	public:
		node* root;
	
	Trie() {
		add(root);
	}
	
	void add(node* &p) {
		p = new node;
		p->count = 0;
		for (char ch='a'; ch<='z'; ch++) p->c[ch] = nullptr;
	}

	void insert(string s) {
		long lengths = s.length();
		node* p = root;
		FOR(i, 0, lengths-1) {
			if (p->c[s[i]]==nullptr) add(p->c[s[i]]);
			p = p->c[s[i]];
		}
		p->count++;
	}
	
	long find(string s) {
		long lengths = s.length();
		node* p = root;
		FOR(i, 0, lengths-1) p = p->c[s[i]];
		return p->count;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long n;
	cin >> n;
	Trie trie;
	FOR(i, 1, n) {
		cin >> s[i];
		trie.insert(s[i]);
	}

	sort(s+1, s+1+n);
	
	FOR(i, 1, n) 
	if (trie.find(s[i])%2!=0) return cout << s[i], 0;
	return 0;
}
