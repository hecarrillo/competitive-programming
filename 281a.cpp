/*
Name: Word Capitalization
Submitted: AC
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  if (s[0] >= 97){
    s[0] -= 32;
  } //se puede hacer con s[0].toupper();
  cout << s << endl;
}
