#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll N, K, A[200002];

bool check(ll m) {
  ll cnt = 0;
  for (ll i = 1; i <= N; i++) {
    if (A[i] >= m) continue;
    cnt += (m - A[i] + i - 1) / i;
    if (cnt > K) return false;
  }
  return cnt <= K;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];

  ll lo = 1, hi = 8e18;
  while (lo + 1 < hi) {
    ll mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }
  cout << lo;
}