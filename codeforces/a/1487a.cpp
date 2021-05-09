/*
Name: Arena
Status: AC
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  while(n--) {
    int p; cin >> p;
    vector<int> a;
    int winners = 0;
    while(p--){
      int person; cin >> person;
      a.push_back(person);
    }
    sort(a.begin(), a.end());
    int last = a[0];
    int min = a[0];
    for (int i = 1; i < a.size(); i++){
      if (a[i] > last or a[i] > min) winners ++;
      last = a[i];
    }
    cout << winners << "\n";
  }
}
