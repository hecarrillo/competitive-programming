/*
Name: Free Ice Cream
Status: AC
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  unsigned long long ice; cin >> ice;

  int distress = 0;

  for (int i = 0; i < n; i++){
    char pos; cin >> pos;
    unsigned long long ask; cin >> ask;
    if(pos == '+') ice += ask;
    if(pos == '-') {
      if (ask > ice) distress += 1;
      else ice = ice - ask;
    }
  }

  cout << ice << " " << distress << "\n";
}
