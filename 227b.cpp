#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<int, int> bis;
  long inOrderComp = 0; //first to print
  long reverseComp = 0; //second to print
  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    bis[temp] = i;
  }
  int comps;
  cin >> comps;
  unordered_set<int> queries;
  for (int i = 0; i < comps; i++){
    int temp;
    cin >> temp;
    if (!(queries.find(temp) == queries.end())) continue;
    queries.insert(temp);
    inOrderComp += bis[temp] + 1;
    reverseComp += n - bis[temp];
  }
  cout << inOrderComp << ' ' << reverseComp << '\n';
}
