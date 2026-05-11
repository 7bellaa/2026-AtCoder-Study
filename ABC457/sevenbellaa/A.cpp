#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  int x;
  cin >> x;
  cout << v[x - 1];
}