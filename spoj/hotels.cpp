/*
Status: AC
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n; int dinero; cin >> n >> dinero;
  vector<int> hoteles;
  while(n--) {
    int valor; cin >> valor;
    hoteles.push_back(valor);
  }
  if (hoteles.size() < 2) {
    if (hoteles[0] <= dinero) {
      cout << hoteles[0] << "\n";
      return 0;
    }
  }
  int i1 = 0;
  int i2 = 1;
  int maxi = (hoteles[0] <= dinero)? hoteles[0] : 0;
  int suma = (hoteles[0] <= dinero)? hoteles[0] : 0;
  if (suma == dinero) {
    cout << suma << "\n";
    return 0;
  }
  while(i2 < hoteles.size() && i1 <= i2) {
    int plusLast = suma + hoteles[i2];
    if(plusLast == dinero) {
      cout << dinero << "\n";
      return 0;
    }
    if (plusLast > dinero) {
      suma -= hoteles[i1];
      i1++;
    } else if (plusLast < dinero) {
      suma = plusLast;
      maxi = max({suma, maxi});
      i2++;
    } else if (i1 == i2) {
      i2++;
    }
  }
  cout << maxi << "\n";
  return 0;
}
