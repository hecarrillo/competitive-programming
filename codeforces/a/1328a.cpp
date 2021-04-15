/*
Name: Divisibility Problem
Status: AC
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;

  for (int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    if (a % b == 0) {
      cout << 0 << "\n";
      continue;
    }
    // int div = (a / b) + 1;
    // cout << (div * b) - a; this is the better solution since it does not use %
    cout << b - (a % b) << "\n";
  }
}
