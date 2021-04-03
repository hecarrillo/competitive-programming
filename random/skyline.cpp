/**
Name: skyLine
Status: Brute force Implementation working
**/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> skyline(vector<vector<int>>& buildings) {
    int maxRightIndex = 0;
    for(vector<int> e : buildings){
        maxRightIndex = max({e[1], maxRightIndex});
    }
    vector<int> skyLineBuildings((maxRightIndex+1)*2,0);
    vector<vector<int>> ans;
    for (vector<int> e : buildings){
        for(int i = e[0]*2; i <= e[1]*2; i++){
            skyLineBuildings[i] = max({skyLineBuildings[i], e[2]});
        }
    }

    skyLineBuildings.push_back(0);

    int lastHeight = 0;
    for(int i = 0; i < skyLineBuildings.size(); i++){
        if (skyLineBuildings[i] != lastHeight) ans.push_back({i/2, skyLineBuildings[i]});
        lastHeight = skyLineBuildings[i];
    }

    return ans;
}

int main() {
  int nBuildings = 0;
  cout << "Insert Number of Buildings" << endl;
  cin >> nBuildings;
  vector<vector<int>> buildings(nBuildings, {0,0,0});
  for (int i = 0; i < nBuildings; i++){
    cout << "Insert building " << i + 1 << " with the following format: L R H \n";
    int L, R, H;
    cin >> L >> R >> H;
    buildings[i][0] = L;
    buildings[i][1] = R;
    buildings[i][2] = H;
  }
  cout << "\n" << "Resulting Skyline:" << "\n";
  vector<vector<int>> ans = skyline(buildings);
  for (vector<int> e : ans){
      cout << "[" << e[0] << "," << e[1] << "]" << "\n";
  }
}
