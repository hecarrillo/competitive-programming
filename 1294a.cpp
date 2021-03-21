/*
Name: Collecting Coins
Submitted: AC
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  int t = 0;
  int a, b, c, n;
  cin >> t;
  for (int i = 0; i < t; i++){
    cin >> a >> b >> c >> n;
    int maxC = max({a, b, c});
    int overHead = (maxC - a) + (maxC - b) + (maxC - c);
    if(n < overHead){
      cout << "NO" << "\n";
    } else {
      if ((n - overHead) % 3 == 0|| n - overHead == 0){
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }
}
