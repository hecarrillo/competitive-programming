#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  unordered_map<int, int> teams = {
    {1, 0}, {2, 0}, {3, 0}, {4, 0}
  };
  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    teams[temp] = teams[temp] + 1;
  }

  int total = teams[4];
  total += teams[3];
  total += teams[2] / 2;
  if(teams[2] & 1) total += 1;
  teams[1] = teams[1] - teams[3];
  teams[1] = teams[1] - 2*(teams[2]%2);
  if(teams[1] > 0) total += ceil(teams[1]/4.0);
  cout << total << "\n";
}
