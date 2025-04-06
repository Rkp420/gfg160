#include <iostream>
using namespace std;

vector<int> make_lps(string &pat)
{
    vector<int> temp(pat.size(), 0);
    int len = 0, i = 1;
    while (i < pat.size())
    {
        if (pat[len] == pat[i])
        {
            len++;
            temp[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = temp[len - 1];
            else
            {
                temp[i] = 0;
                i++;
            }
        }
    }
    return temp;
}

vector<int> isPatternMatch(string s, string p){
    vector<int> ans;
    
    // Make Lps Array
    vector<int> lps = make_lps(p);

    // Time To Apply Kmp
    int i = 0;
    int j = 0;
    while(i < s.size()){
        if(s[i] == p[j]){
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }

        if(j == p.size()){
            int idx = (i - j + 1); // 1 - based Indexing
            ans.push_back(idx);
            j = lps[j - 1];
        }
    }

    return ans;
}

class Solution
{
public:
    vector<int> search(string &pat, string &txt)
    {

        vector<int> indices;
        int n = txt.size();
        int m = pat.size();

        for (int i = 0; i <= n - m; i++)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }

            if (j == m)
                indices.push_back(i);
        }

        return indices;
    }
};


int main()
{
    string s;
    cin >> s;

    string pattern;
    cin >> pattern;

    vector<int> lps = make_lps(pattern);

    for(int i = 0; i < lps.size(); i++) cout << lps[i] << " " << endl;
    vector<int> kmp =  isPatternMatch(s, pattern);

    for(int i = 0; i < kmp.size(); i++) cout << kmp[i] << " ";

    return 0;
}