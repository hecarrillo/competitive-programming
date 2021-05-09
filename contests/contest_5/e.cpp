#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<long> ans (n,0);

  for (vector<int> & query : queries){
    long a = query[0] - 1;
    long b = query[1] - 1;
    long k = query[2];
    ans[a] += k;
    if (b + 1 < n) ans[b + 1] -= k;
  }
}
