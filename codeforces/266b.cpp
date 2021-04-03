/*
Name: Queue at the School
Status: AC
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  int qL;
  int shifts;
  string q;
  cin >> qL >> shifts >> q;
  int lastB = qL;
  for (int k = 0; k < shifts; k++){
    for (int i = qL - 2; i >= 0; i--){
      if(q[i] == 'B' && q[i+1] == 'G'){
        q[i] = 'G';
        q[i + 1] = 'B';
        i--;
      }
    }
  }
  for (char e : q){
    cout << e;
  }
  cout << endl;
}


// 6 2
// BBGBBG
// BGBBGB
// //GBBGBB
// EXP GBBGBB
