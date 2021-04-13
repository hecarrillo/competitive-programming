/*
Name: Horror dash
Status: AC
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    int c; cin >> c;
    int maxMS; cin >> maxMS;
    for (int j = 1; j < c; j++) {
      int currChild; cin >> currChild;
      maxMS = max({maxMS, currChild});
    }
    cout << "Case " << i + 1 << ": " << maxMS << "\n";
  }
}
