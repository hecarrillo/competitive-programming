/*
Name: Array with Odd Sum
Submitted: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++){
    int len = 0;
    cin >> len;
    int arr[len];
    int k = 0;
    int m = 0;
    for (int j = 0; j < len; j++){
      cin >> arr[j];
      if (arr[j] % 2 == 0) k++;
      else m++;
    }
    if (m > 0 && ((m % 2 == 0 && k > 0) || (m % 2 != 0))){
       cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}
