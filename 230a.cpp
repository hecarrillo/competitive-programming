/*
Name: Dragons
Status: AC
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, health;
  cin >> health >> n;
  vector<pair<int, int>> dragons(n);
  for (auto &e : dragons){
    cin >> e.first >> e.second;
  }
  sort(dragons.begin(), dragons.end());
  for (auto &e : dragons){
    if(health > e.first) {
      health += e.second;
    } else {
      cout << "NO" << "\n";
      return 0;
    }
  }
  cout << "YES" << "\n";
}
