/*
Name: Sparse Arrays (HackerRank)
Status: AC
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
  unordered_map<string, int> sMap;
  vector<int> ans;
  for (string s : strings){
    if(sMap.find(s) == sMap.end()) sMap.insert(make_pair(s, 1));
    else sMap[s] = ++sMap[s];
  }
  for (string query : queries){
    if(sMap.find(query) == sMap.end()) ans.push_back(0);
    else ans.push_back(sMap[query]);
  }
  return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
