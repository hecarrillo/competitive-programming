/*
Name: C. Cd and pwd commands
Status: WA
*/

#include <bits/stdc++.h>

using namespace std;

void pwd(vector<string> & dir){
  cout << "/";
  for(string & s : dir){
    cout << s << "/";
  }
  cout << "\n";
}

vector<string> split (string &s) {
    vector<string> ans;
    stringstream ss (s);
    string item;

    while (getline (ss, item, '/')) {
        if(item == "") continue;
        ans.push_back (item);
    }

    return ans;
}

int main(){
  int n; cin >> n;
  vector<string> dir;
  while(n--){
    string s; cin >> s;
    if (s == "pwd") pwd(dir);
    else {
      string command; cin >> command;
      string temp;
      vector <string> commands = split(command);
      if(command[0] == '/') {
        int len = dir.size();
        if (commands[0] != dir[len - 1]){
          dir.clear();
        }
      }
      for (string s : commands){
        if(s == "..") dir.pop_back();
        else dir.push_back(s);
      }
    }
  }
}
