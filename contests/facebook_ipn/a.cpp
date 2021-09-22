#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int initialN = n;
    while (n--)
    {
        string inString;
        cin >> inString;
        vector<char> charqueue = {'k', 'o', 'o', 'b', 'e', 'c', 'a', 'f'};
        for (char &e : inString)
        {   
            if (charqueue.size() == 0) break;
            if (charqueue.back() == e) charqueue.pop_back();
        }
        cout << "Case #" << initialN - n;
        if (charqueue.size() != 0)
            cout << ": NO" << endl;
        else
            cout << ": YES" << endl;
    }
    return 0;
}