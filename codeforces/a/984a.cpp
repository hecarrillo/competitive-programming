/**
Name: Game
Status: AC
**/
#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> numbers (n);
  for (int & number : numbers){
    cin >> number;
  }
  sort(numbers.begin(), numbers.end());
  if (n & 1) cout << numbers[n/2] << "\n";
  else cout << numbers[n/2 - 1] << "\n";
}
