/*
  Status: AC
  Name: Boxes Packing
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  int visible = n;
  vector<long long int> boxes;
  while(n--){
    int curr; cin >> curr;
    boxes.push_back(curr);
  }
  sort(boxes.begin(), boxes.end(), greater<int>());
  queue<long long int> b;
  b.push(boxes[0]);
  int index = 1;

  while (index < boxes.size()){
    if(b.front() > boxes[index]) b.pop();
    b.push(boxes[index]);
    index++;
  }
  cout << b.size() << "\n";
}
