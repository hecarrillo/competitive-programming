#include <bits/stdc++.h>

using namespace std;

int main(){
  string s; cin >> s;
  int len = s.size();
  int diff = 0;
  for (int i = 0; i < len/2; i ++){
    // cout << s[i] << " " << s[len - 1 - i] << endl;
    if(s[i] != s[len - 1 - i]) diff++;
  }
  if((diff <= 1 && (len&1)) or (diff == 1 && !(len&1))) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}
