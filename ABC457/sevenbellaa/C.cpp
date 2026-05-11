#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll N, K;
vector<ll> c, l, v[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;
  c.resize(N), l.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> l[i];
    for (int j = 0; j < l[i]; j++) {
      int t;
      cin >> t;
      v[i].push_back(t);
    }
  }
  for (ll& i : c) cin >> i;

  for (int i = 0; i < N; i++) {
    if (c[i] * l[i] >= K) {
      int idx = K % l[i] - 1;
      if (idx == -1) idx = l[i] - 1;
      cout << v[i][idx];
      break;
    }
    K -= c[i] * l[i];
  }
}