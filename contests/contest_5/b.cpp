#include <bits/stdc++.h>

using namespace std;

int main(){
  unordered_map<string, bool> names;
  int n; cin >> n;

  while(n--){
    string name; cin >> name;
    if(names[name]) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
      names[name] = true;
    }
  }
}
