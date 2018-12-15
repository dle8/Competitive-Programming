#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
using namespace std;

typedef long long ll;

bool diff(string file1, string file2) {
  ll ans1, ans2;
  ifstream out(file1.c_str());
  out >> ans1;
  ifstream ans(file2.c_str());
  ans >> ans2;
  cout << ans1 << " " << ans2 << '\n';
  return (ans1 == ans2);
}

int main() {
  long sign[] = {-1, 1};
  FOR(current_test, 1, 100) {
    srand(time(NULL));
    ofstream inp("input.txt");
    long n = 1500;
    inp << n << '\n';
    set<pair<long, long>> mset; mset.clear();
    FOR(i, 1, n) {
      while (true) {
        long factor = rand() % 2;
        long x = rand() % 50 * sign[factor];
        factor = rand() % 2;
        long y = rand() % 50 * sign[factor];
        if (mset.count({x, y}) == 0) {
          mset.insert({x, y});
          inp << x << " " << y << '\n';
          break;
        }
      }
    }
    inp.close();
    system("g++ -o run test2.cpp");
    system("./run");
    system("g++ -o run test.cpp");
    system("./run");
    if (diff("ans.txt", "output.txt") == 0) {
      cout << "Test #" << current_test << ": WRONG!";
      break;
    }
    else cout << "Test #" << current_test << ": CORRECT";
    // if (system("fc ans.txt output.txt") != 0) cout << "Test #" << current_test << ": WRONG!";
    // else cout << "Test #" << current_test << ": CORRECT";
    cout << '\n';
  }
  return 0;
}
