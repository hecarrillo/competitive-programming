/*
Name: Effective Approach
Status: Testing
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<long, long> bis;
  long inOrderComp = 0; //first to print
  long reverseComp = 0; //second to print
  for (long i = 0; i < n; i++){
    long temp;
    cin >> temp;
    bis.insert(make_pair<long, long>(temp, i))
    bis[temp] = i;
  }
  long nqueries;
  cin >> nqueries;
  for (int i = 0; i < nqueries; i++){
    long query; 
    cin >> query;
    inOrderComp += bis[query] + 1;
    reverseComp += n - bis[query];
  }
  cout << inOrderComp << ' ' << reverseComp << '\n';
}
