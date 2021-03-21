/*
Name: Beautiful Matrix
Submitted: AC
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  int ans = 0;
  bool isOne = false;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> isOne;
      if (isOne) {
        ans = abs (2 - i) + abs(2 - j);
      }
    }
  }
  cout << ans << endl;
}
