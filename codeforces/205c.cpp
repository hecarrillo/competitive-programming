/*
Name: Un Oscar Aburrido
Status:
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned long long lower, upper;
  cin >> lower >> upper;
  lower -= 1;
  unsigned long long oneToLow = (lower+1 >= 10)?
  (lower/10) + (lower % 10) + (9 - lower % 10) : lower;
  unsigned long long oneToUp = (upper >= 10)?
  (upper/10) + (upper % 10) + (9 - upper % 10) : upper;
  cout << oneToUp - oneToLow << "\n";
}
