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

    long n = 10;
    inp << n << '\n';
    FOR(i, 1, n) {
      long tmp = rand() % 2;
      inp << tmp;
    }
    inp << '\n';
    FOR(i, 1, n) {
      long tmp = rand() % 50 + 1;
      inp << tmp;
      if (i != n) inp << " ";
    }
    // input making goes here.

    inp.close();
    system("g++ -o run test.cpp");
    system("./run");
    system("g++ -o run test3.cpp");
    system("./run");
    // system("javac test.java");
    // system("java test");
    if (diff("output.txt", "ans.txt") == 0) {
      cout << "Test #" << current_test << ": WRONG!";
      break;
    }
    else cout << "Test #" << current_test << ": CORRECT";
    cout << '\n';
  }
  return 0;
}
