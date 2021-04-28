/*
Status: AC
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */
struct X {
 int data;
 X * max = nullptr;
};

vector<int> getMax(vector<string> operations) {
  stack<X*> stack;
  vector<int> maximums;
  X * maxN;
  for(string & op : operations){
    if (op[0] == '1') {
      X * insert = new X{stoi(op.substr(2), nullptr, 10), maxN};
      cout << insert -> data << endl;
      if (maxN != nullptr and maxN -> data < insert -> data) {
        maxN = insert;
      }
      stack.push(insert);
    } else if (op[0] == '2' && !stack.empty()){
      X * top = stack.top();
      maxN = top -> max;
      stack.pop();
    } else if (op[0] == '3') {
      maximums.push_back(maxN -> data);
    }
  }
  return maximums;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
