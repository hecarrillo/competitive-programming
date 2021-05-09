#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<string> laraSet;
  vector<string> enyaSet;
  int n, m; cin << n; cin << m;
  while(n--) {
    string s; cin >> s;
    laraSet.push_back(s);
  }
  sort(laraSet.begin(), lara.end());
  while(n--) {
    string s; cin >> s;
    enyaSet.push_back(s);
  }
  sort(enyaSet.begin(), enyaSet.end());
  bool larasTurn = true;
  int larasIndex = 0;
  int enyasIndex = 0;
  while(larasIndex < laraSet.size() && enyasIndex < enyaSet.size()){
    if(larasTurn) {
      if(laraSet[larasIndex] == enyasIndex[enyasIndex]){
        enyasIndex++;
        larasIndex++;
      } else
    } else {

    }
    larasTurn = !larasTurn;
  }
  if (larasIndex == laraSet.size() - 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
