/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
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

using namespace __gnu_pbds;
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Tree;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(), people.end());

      int i = 0;
      int j = people.size() - 1;

      while (i < j) {
        if (people[i] + people[j] <= limit) {
          i++;
          j--;
        }
        else j--;
        boat++;
      }

      return boat;
    }
};

int main() {
	fio;
  int n, limit, weight;
	cin >> n >> limit;
  vector<int> people;
  FOR(i, 1, n) {
    cin >> weight;
    people.pb(weight);
  }

  Solution sol;
  cout << sol.numRescueBoats(people, limit);
	return 0;
}
