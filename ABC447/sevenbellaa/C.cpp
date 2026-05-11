#include <bits/stdc++.h>
using namespace std;

string S, T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> S >> T;
  string cmp1 = S, cmp2 = T;
  erase(cmp1, 'A');
  erase(cmp2, 'A');
  if (cmp1 != cmp2) {
    cout << -1;
    return 0;
  }

  int i = 0, j = 0, ans = 0;
  while (i < S.length() && j < T.length()) {
    if (S[i] == T[j]) {
      ++i, ++j;
      continue;
    }
    if (S[i] == 'A' && T[j] != 'A') {
      ++i;
      ans++;
      continue;
    }
    if (S[i] != 'A' && T[j] == 'A') {
      ++j;
      ans++;
      continue;
    }
  }
  ans += S.length() - i + T.length() - j;
  cout << ans;
}