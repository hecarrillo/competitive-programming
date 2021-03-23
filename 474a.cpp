/**
Name: Keyboard
Status: AC
**/

#include<bits/stdc++.h>

using namespace std;

int main() {
  char shift;
  string word;
  cin >> shift;
  cin >> word;
  vector<char> keys = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g',
  'h','j','k','l',';','z','x','c','v','b','n','m',',','.','/'};
  for (char letter : word){
    for (int i = 0; i < keys.size(); i++){
      if(keys[i] == letter){
        if (shift == 'R'){
          cout << keys[i - 1];
        } else cout << keys[i + 1];
      }
    }
  }
  cout << "\n";
}
