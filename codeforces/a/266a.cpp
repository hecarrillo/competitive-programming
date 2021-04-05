/*
Name: Stones on the Table
Status: AC
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;

  int minToRemove = 0;
  string s; cin >> s;
  char lastDifferent = s[0];

  for (int i = 1; i < s.length(); i++){
    char curr = s[i];
    if (lastDifferent == curr) ++minToRemove;
    else lastDifferent = curr;
  }

  cout << minToRemove << "\n";
}
