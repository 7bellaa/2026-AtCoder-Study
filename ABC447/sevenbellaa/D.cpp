#include <bits/stdc++.h>
using namespace std;

string S;
int cnt[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> S;
  for (char c : S) {
    if (c == 'A')
      cnt[0]++;
    else if (c == 'B' && cnt[0]) {
      cnt[0]--;
      cnt[1]++;
    } else if (c == 'C' && cnt[1]) {
      cnt[1]--;
      cnt[2]++;
    }
  }
  cout << cnt[2];
}