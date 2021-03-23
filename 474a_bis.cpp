/**
Name: Keyboard. Implementation with unordered_map
Status: AC
**/

#include<bits/stdc++.h>

using namespace std;

int main() {
  char shift;
  string word;
  cin >> shift;
  cin >> word;
  unordered_map<char, pair<char, char>> keys = {
    {'q',{' ','w'}}, {'w', {'q','e'}},{'e', {'w','r'}}, {'r', {'e','t'}}, {'t', {'r','y'}}, {'y', {'t','u'}}, {'u', {'y','i'}}, {'i', {'u','o'}}, {'o', {'i','p'}},{'p', {'o',' '}},
    {'a',{' ','s'}}, {'s', {'a','d'}},{'d', {'s','f'}}, {'f', {'d','g'}}, {'g', {'f','h'}}, {'h', {'g','j'}}, {'j', {'h','k'}}, {'k', {'j','l'}}, {'l', {'k',';'}},{';', {'l',' '}},
    {'z',{' ','x'}}, {'x', {'z','c'}},{'c', {'x','v'}}, {'v', {'c','b'}}, {'b', {'v','n'}}, {'n', {'b','m'}}, {'m', {'n',','}}, {',', {'m','.'}}, {'.', {',','/'}},{'/', {'.',' '}}
  };
  for(char & letter : word){
    pair<char, char> & temp = keys[letter];
    if(shift == 'R') cout << temp.first;
    else cout << temp.second;
  }
  cout << "\n";
}
