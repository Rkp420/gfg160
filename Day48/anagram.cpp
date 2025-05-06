#include <iostream>
using namespace std;

// User function Template for C++

class Solution
{
public:
    vector<vector<string>> anagrams(vector<string> &arr)
    {
        // code here
        unordered_map<string, vector<string>> anagramGroups;
        vector<string> keyOrder;

        for (string &word : arr)
        {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());

            if (anagramGroups.find(sortedWord) == anagramGroups.end())
            {
                keyOrder.push_back(sortedWord);
            }

            anagramGroups[sortedWord].push_back(word);
        }

        vector<vector<string>> result;
        for (string &key : keyOrder)
        {
            result.push_back(anagramGroups[key]);
        }

        return result;
    }
};


int main()
{
    return 0;
}