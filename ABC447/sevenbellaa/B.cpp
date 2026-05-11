#include <bits/stdc++.h>
using namespace std;

int mx, cnt[26];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  for (char c : s) {
    int idx = c - 'a';
    ++cnt[idx];
    mx = max(mx, cnt[idx]);
  }

  for (char c : s) {
    if (cnt[c - 'a'] < mx) cout << c;
  }
}