/*
Name: Jzzhu and Children
Status: AC
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m; cin >> n >> m;
  vector<int> candies;
  for (int i = 0; i < n; i++){
    int a = 0;
    cin >> a;
    candies.push_back(a);
  }

  int maxRounds = 0;
  int maxIndex = 0;
  for(int i = 0; i < n; i++){
    int rounds = candies[i] / m;
    rounds = (candies[i] % m != 0)? rounds + 1 : rounds;
    if (rounds >= maxRounds) {
      maxIndex = i;
      maxRounds = rounds;
    }
  }

  cout << maxIndex + 1 << "\n";
}
