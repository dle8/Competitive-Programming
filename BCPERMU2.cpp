#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define pb push_back
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	long n;
	/*
	vector<int> permutation;
	cin >> n;
	FOR(i, 1, n) permutation.push_back(i);
	do {
		for(auto it = permutation.begin(); it!=permutation.end(); it++) cout << *it;
		cout << endl;
	} while (next_permutation(permutation.begin(), permutation.end()));
	*/
	
	vector<char> permutation;
	permutation.pb('a');
	permutation.pb('b');
	permutation.pb('c');
	
	do {
		for (auto it = permutation.begin(); it!=permutation.end(); it++) cout << *it;
		cout << endl;
	} while (next_permutation(permutation.begin(), permutation.end()));
	return 0;
}
