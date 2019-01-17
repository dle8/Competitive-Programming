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

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); } 
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

long hand(char c) {
	if (c == 'd' || c == 'f') return 1;//left hand
	return 2;
}

int main() {
	fio;
		
	long test_cases, n;
	double time, totalTime;
	string word;
	
	cin >> test_cases;
	map<string, double> Map;
	FOR(current_test, 1, test_cases) {
		cin >> n;
		totalTime = 0;
		Map.clear();
		FOR(i, 1, n) {
			cin >> word;
			if (Map[word] != 0) {
				totalTime += (Map[word] / 2);
				continue;	
			}
			
			time = 0;
			FOR(j, 0, int(word.length()) - 1) {
				if (j == 0) {
					time += 0.2;
					continue;
				}
				if (hand(word[j]) == hand(word[j - 1])) time += 0.4;
				else time += 0.2;
			}
			
			Map[word] = time;
			totalTime += time;
		}
		
		cout << totalTime * 10 << "\n";
	}
	
	return 0;
}
