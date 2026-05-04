#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll DIV = 10007;

ll power(ll n, ll k) {
  ll res = 1;
  n %= DIV;

  while (k) {
    if (k & 1) res = (res * n) % DIV;
    n = (n * n) % DIV;
    k /= 2;
  }
  return res;
}

ll calcOne(ll l) {
  if (l == 1) return 1;
  ll half = l / 2;

  ll res = 1;
  res = res * (calcOne(l - half)) % DIV * power(10, half) % DIV;
  res = (res + (calcOne(half))) % DIV;
  return res;
}

// N/M % DIV

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll K, M;
  cin >> K >> M;

  vector<pair<ll, ll>> v;
  vector<ll> pfs(K + 1);
  for (int i = 0; i < K; i++) {
    ll c, l;
    cin >> c >> l;
    v.emplace_back(c, l);
  }

  for (int i = K - 1; i >= 0; i--) {
    pfs[i] = v[i].second + pfs[i + 1];
  }

  ll ans = 0;
  for (int i = 0; i < K; i++) {
    ans += v[i].first * calcOne(v[i].second) % DIV *
           power(10, pfs[i] - v[i].second) % DIV;
    ans %= DIV;
  }
  ans = ans * power(M, DIV - 2) % DIV;
  cout << ans;
}