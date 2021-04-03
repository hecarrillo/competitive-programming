/*
Name: 
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  long last;
  int maxGains = 1;
  int streak = 1;
  long temp;
  cin >> last;
  for (int i = 1; i < n; i++){
    cin >> temp;
    if(temp >= last){
      streak += 1;
      maxGains = max({maxGains, streak});
    } else {
      streak = 1;
    }
    last = temp;
  }
  cout << maxGains << "\n";
}
