#include <bits/stdc++.h>
using namespace std;

int cur[101], nxt[101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    cur[a]++;
    nxt[b]++;
  }

  for (int i = 1; i <= M; i++) {
    cout << nxt[i] - cur[i] << '\n';
  }
}