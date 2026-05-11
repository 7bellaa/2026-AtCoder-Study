#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  if ((a + 1) / 2 >= b)
    cout << "Yes";
  else
    cout << "No";
}