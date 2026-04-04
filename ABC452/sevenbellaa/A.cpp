#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s[5] = {"1 7", "3 3", "5 5", "7 7", "9 9"};
  string t;
  getline(cin, t);
  for (int i = 0; i < 5; i++) {
    if (t == s[i]) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}