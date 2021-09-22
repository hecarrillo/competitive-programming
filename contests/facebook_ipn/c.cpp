#include <iostream>
#include <vector>

using namespace std;

int sumEntries(vector<int> &spaces, int left, int right)
{
    if (left == 0)
        return spaces[right];
    else
        return spaces[right] - spaces[left - 1];
}

int main()
{
    int n;
    cin >> n;
    int initialN = n;
    while (n--)
    {
        cout << "Case #" << initialN - n << ": ";
        int nSpaces;
        cin >> nSpaces;
        vector<int> spaces(nSpaces, -1);
        int maxGains = -2147483647;
        int last = 0;
        while (nSpaces--)
        {
            int temp;
            cin >> temp;
            spaces.push_back(temp + last);
            last = temp;
            maxGains = max({temp, maxGains});
        }

        for (int i = 1; i < spaces.size(); i++)
        {
            int l = 0;
            int r = i;
            while(r < spaces.size())
            {
                maxGains = max({maxGains, sumEntries(spaces, l, r)});
                l += 1;
                r += 1;
            }
        }
        cout << maxGains << endl;
    }
}