#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    void printCombinations(vector<vector<char> > pl, string digits, int index)
    {
        for (char e : digits){
            
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<vector<char> > phoneLetters{
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}};
        printCombinations(phoneLetters, digits, 0);
    }
};