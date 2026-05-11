#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N_MAX = 200002, DIV = 998244353;
int N, M, parent[N_MAX];
pair<int, int> edge[N_MAX];

int find(int x) { return parent[x] = (x == parent[x]) ? x : find(parent[x]); }

void merge(int x, int y) {
  x = find(x), y = find(y);
  parent[y] = x;
}

ll power(ll n, ll k) {
  ll res = 1;
  while (k) {
    if (k & 1) res = res * n % DIV;
    n = n * n % DIV;
    k >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  iota(parent, parent + N + 1, 0);
  for (int i = 1; i <= M; i++) {
    int u, v;
    cin >> u >> v;
    edge[i] = {u, v};
  }

  ll cnt = 0, ans = 0;
  for (int i = M; i > 0; i--) {
    auto [u, v] = edge[i];
    if (find(u) == find(v)) continue;
    if (cnt < N - 2) {
      merge(u, v);
      cnt++;
    } else
      ans = (ans + power(2, i)) % DIV;
  }
  cout << ans;
}