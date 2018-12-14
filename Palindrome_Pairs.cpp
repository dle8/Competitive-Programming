/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define eps 1e-9

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> Point;
typedef pair<Point, Point> line;
struct strLine { ld a, b, c; };

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

const double pi = 3.141592653589793;

typedef vector<vi> vii;

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

struct node {
	vi v;
	node* c[255];
}

struct Trie {
	node* root;

	Trie() {
		add(root);
	}

	void add(node* &p) {
		p = new node;
		(p->v).clear();
		FOR(i, 0, 254) p->c[i] = NULL;
	}

	void insert(string str, long index) {
		node* p = root;
		REP(i, int(str.size()) - 1, 0) {
			if (p->c[str[i]] == NULL) add(p->c[str[i]]);
			p = p->c[str[i]];
		}
		(p->v).pb(index);
	}

	vi found(string str) {
		node* p = root;
		vi v; v.clear();
		FOR(i, 0, int(str.size()) - 1) {
			if (p->c[str[i]] == NULL || (p->v).size() != 0) return v;
			p = p->c[str[i]];
		}

		return (p->v);
	}
}

bool cmp(const string &x, const string &y) {
	return (int(x.size()) < int(y.size()));
}

bool isPalindrome(string s) {
	FOR(i, 0, (int(s.size()) - 1) / 2) {
		if (s[i] != s[int(s.size()) - 1 - i]) return false;
	}
	return true;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
			Trie trie;

			sort(words.begin(), words.end(), &cmp);
			FOR(i, 0, int(words.size()) - 1) trie.insert(words[i], i);

			vii res; res.clear();
			FOR(i, 0, int(words.size()) - 1) {
				vi v = trie.found(words[i]);
				if (v.size() == 0) continue;

				for (auto iter = v.begin(); iter = v.end(); iter++) {
					string s = words[*iter];
					string tmp = s.substr(0, int(s.length()) - int(words[i].length()));
					if (isPalindrome(tmp)) {
						vi temp; temp.clear();
						temp.pb(i);
						temp.pb(*iter);
						res.pb(temp);
					}
				}
			}

			return res;
    }
};

int main() {
	fio;

	cin >> n;
	vector<string> words; words.clear();
	FOR(i, 1, n) {
		cin >> str;
		words.pb(str);
	}

	Solution sol;
	vii ans = sol.palindromePairs(words);
	for (auto outer = ans.begin(); outer != ans.end(); outer++) {
		for (auto iter = (*outer).begin(); iter != (*outer).end(); iter++)
		cout << *iter << " ";
		cout << "\n";
	}

	return 0;
}
