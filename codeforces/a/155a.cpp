/*
Name: I love %username%
Status: Coding
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;

  if (n <= 1) {
    cout << 0;
    return 0;
  }

  int maxPoints, minPoints;

  cin >> maxPoints;
  minPoints = maxPoints;
  int count = 0;

  for (int i = 0; i < n; i++){
    int curr; cin >> curr;
    if (curr >  maxPoints || curr < minPoints) {
     ++count;
     minPoints = min({curr, minPoints});
     maxPoints = max({curr, maxPoints});
    }
  }
  cout << count << endl;
}
