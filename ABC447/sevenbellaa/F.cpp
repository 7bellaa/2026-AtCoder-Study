#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<vector<int>> graph(N + 1);
  for (int i = 0; i < N - 1; i++) {
    int A, B;
    cin >> A >> B;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }

  int ans = 1;
  auto dfs = [&](this auto& self, int prev, int cur) -> int {
    vector<int> v;
    for (int nxt : graph[cur]) {
      if (prev == nxt) continue;
      int child_dp = self(cur, nxt);
      if (child_dp > 0) v.push_back(child_dp);
    }
    ranges::sort(v, greater<>());

    int deg = graph[cur].size();
    if (deg >= 3 && v.size() >= 1) ans = max(ans, v[0] + 1);
    if (deg >= 4 && v.size() >= 2) ans = max(ans, v[0] + v[1] + 1);

    if (deg >= 4 && v.size() >= 1) return v[0] + 1;
    if (deg >= 3) return 1;
    return -1;
  };
  dfs(0, 1);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int Q;
  cin >> Q;
  while (Q--) solve();
}