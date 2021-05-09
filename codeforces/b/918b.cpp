/*
Name: Radio Station
Status: AC
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  unordered_map<string, string> names;
  int n, m; cin >> n >> m;

  while(n--){
    string name, ip; cin >> name >> ip;
    names.insert({ip, name});
  }

  while(m--){
    string command, ip; cin >> command >> ip;
    string ipSubs = ip.substr(0, ip.size()-1);
    cout << command << " " << ip << " #" << names[ipSubs] << "\n";
  }
}
