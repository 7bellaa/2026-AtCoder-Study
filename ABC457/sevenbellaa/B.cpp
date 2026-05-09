#include <bits/stdc++.h>
using namespace std;

int n, x, y;
vector<int> v[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    for (int j = 0; j < l; j++) {
      int t;
      cin >> t;
      v[i].push_back(t);
    }
  }
  cin >> x >> y;
  cout << v[x - 1][y - 1];
}