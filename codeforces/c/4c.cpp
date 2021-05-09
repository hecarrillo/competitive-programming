/*
Name: Registrarion System
Status: AC
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  unordered_map<string, int> names;
  int n; cin >> n;

  while(n--){
    string name; cin >> name;
    if(names.find(name) == names.end()) {
      cout << "OK" << "\n";
      names[name] = 1;
    } else {
      cout << name << names[name] << "\n";
      names[name] = names[name] + 1;
    }
  }
}
