/*
Name: Young Physicist
Submitted: AC
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
  int nTests = 0;
  int axisSums[3] = {0,0,0};
  string res;
  cin >> nTests;
  for (int i = 0; i < nTests; i++){
    for (int j = 0; j < 3; j++){
      int curr = 0;
      cin >> curr;
      axisSums[j] += curr;
    }
  }
  res = (axisSums[0] == 0 && axisSums[1] == 0 && axisSums[2] == 0)? "YES" : "NO";
  cout << res << endl;
}
