#if 1
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <map>
#include <cmath>
#include <cstring>
#include <complex>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

template <typename T>
T readVal()
{
  T num;
  cin >> num;
  return num;
}

template <typename T>
void writeVal(T num)
{
  cout << num;
}

template <typename T>
void write2Val(T num0, T num1)
{
  cout << num0 << " " << num1;
}

typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
const ll MOD = 1000000007LL;

vector<int> arr;
string gs;
ll dp[205][205][205];

ll solve(int sidx, int eidx, int prefix)
{
  if (eidx - sidx == 0) {
    return 0;
  }

  ll &val = dp[sidx][eidx][prefix];
  if (val != 0) {
    return val;
  }

  val = arr[prefix] + solve(sidx + 1, eidx, 1);
  for (int i = sidx + 1; i < eidx; ++i) {
    if (gs[i] == gs[sidx]) {
      val = max(val, solve(sidx + 1, i, 1) + solve(i, eidx, prefix + 1));
    }
  }
  return val;
}

int main()
{
  /*ios::sync_with_stdio(false);
  cin.tie(NULL);*/
	freopen("input.txt", "r", stdin);
	freopen("ans.txt", "w", stdout);
  int n = readVal<int>();
  gs = readVal<string>();
  arr.resize(n+1,0);
  for (int i = 0; i < n; ++i) {
    arr[i+1] = readVal<int>();
  }

  memset(dp,0,sizeof(dp));

  cout << solve(0, n, 1) << endl;
	fclose(stdin);
  return 0;
}
#endif
