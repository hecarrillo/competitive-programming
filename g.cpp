#include <bits/stdc++.h>

using namespace std;

int main(){
    int w;

    cin >> w;

    if (w & 1) {
      cout << "NO" << "\n";
      return 0;
    }

    int left = w / 2;
    int right = w / 2;
    for (int i = left; i > 0 ; i--){
      if (!(left & 1) && !(right & 1)) {
        cout << "YES" << "\n";
        return 0;
      } else {
        left += 1;
        right -= 1;
      }
    }

    cout << "NO" << "\n";

}
