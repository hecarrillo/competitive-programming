/*
Name: Lights Out
Status: Testing
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<vector<bool>> matriz(3, {1,1,1});

  for(int i = 0; i < 3; i ++){
    for(int j = 0; j < 3; j++){
      int curr;
      cin >> curr;
      if (curr & 1) {
        for(int k = 0; k < 3; k++){
          matriz[i][k] = !matriz[i][k];
          for(int l = 0; l < 3; l++){
            if(l == i) continue;
            matriz[l][j] = !matriz[l][j];
          }
        }
      }
    }
  }
  //flip rows

  for(vector<bool> row : matriz){
    for(bool e : row){
      cout << e;
    }
    cout << "\n";
  }

}
