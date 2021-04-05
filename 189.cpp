/*
Name: Cut Ribbon
Status: Coding
*/

#include <bits/stdc++.h>

using namespace std;

int abcSum(vector<int> * coef, vector<int> * abc){
  return (*coef)[0] * (*abc)[0] + (*coef)[1] * (*abc)[1] + (*coef)[2] * (*abc)[2];
}

int main(){
  int length; cin >> length;
  int a, b, c; cin >> a >> b >> c;

  vector<int> abc = {a, b, c};
  sort(abc.begin(), abc.end());

  vector<int> coef = {a/length, 0 , 0};

  if (abc[0]*a/length == length) {
    cout << coef[0] << "\n";
  }
    return 0;

  while()
  for (int i = 0; i < abc.length(); i++) {
    for (int j = 1 ; )
  }

}

/*
Assuming abc is sorted:

na + mb + oc = length

aaaaaab_

aaa
aab
*/
