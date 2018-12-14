#include <bits/stdc++.h>
#define maxm 250000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define oo 1000000000
using namespace std;

struct node {
	string w;
	long length;
};

struct trieNode {
	long end;
	trieNode* c[255];
	
	trieNode() {
		for (char ch='a';  ch<='z'; ch++) c[ch] = nullptr;
	}
};

node a[maxm];

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

class Trie {
	public:
		trieNode* root;
		long longestChain;
	
	Trie() {
		add(root);
		longestChain = -oo;
	}
	
	void add(trieNode* &p) {
		p = new trieNode;
		p->end = 0;
		for (char ch='a'; ch<='z'; ch++) p->c[ch] = nullptr;
	}
	
	void insert(string s) {
		long lengths = s.length();
		long count = 0;
		trieNode* p = root;
		FOR(i, 0, lengths-1) {
			if (p->c[s[i]]==nullptr) add(p->c[s[i]]);
			p = p->c[s[i]];
			if (i==lengths-1) p->end++;
			if (p->end!=0) count++;
		}
		longestChain = max(longestChain, count);
	}
	
	long getLongestChain() {
		return longestChain;
	}
};

bool compare(const node&x, const node&y) {
	return (x.length<y.length);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long m;
	cin >> m;
	FOR(i, 1, m) {
		cin >> a[i].w;
		a[i].length = a[i].w.length();		
	}
	
	sort(a+1, a+1+m, compare);
	
	Trie trie;
	FOR(i, 1, m) trie.insert(a[i].w);
	
	cout << trie.getLongestChain();
	return 0;
}
