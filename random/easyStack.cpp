/*
Name: Easy Stack
Status: AC
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  int n; cin >> n;
  stack<unsigned int>op;
  while(n--){
    int operation; cin >> operation;
    if(operation == 1){
      unsigned int number; cin >> number;
      op.push(number);
    }
    if(operation == 2 && !op.empty()){
      op.pop();
    } else if(operation == 3) {
      if(op.empty()) cout << "Empty!" << "\n";
      else {
        cout << op.top() << "\n";
      }
    }
  }
}
