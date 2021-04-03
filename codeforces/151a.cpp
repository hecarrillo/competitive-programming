/*
Name: Favela y los shots
Status: AC
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int miembros, botellas, ml, limones, rodajas, gsalsa, bebidaml, bebidasalsa;
  cin >> miembros >> botellas >> ml >> limones >> rodajas >> gsalsa >> bebidaml >> bebidasalsa;
  int nRodajas = limones * rodajas;
  int nBebida = (botellas * ml) / bebidaml;
  int nSalsa = gsalsa / bebidasalsa;
  int maxShots = min({nRodajas, nBebida, nSalsa});
  cout << maxShots/miembros << "\n";
}
