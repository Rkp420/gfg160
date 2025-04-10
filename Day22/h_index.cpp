#include <iostream>
using namespace std;

// Extreme bruteforce

// User function Template for C++
class Solution
{
public:
    // Function to find hIndex
    int hIndex(vector<int> &citations)
    {
        // Extreme BruteForce
        int n = citations.size();

        int h = 0;
        for (int i = 1; i <= n; i++)
        {
            int count = 0;
            for (int c : citations)
            {
                if (c >= i)
                    count++;
            }

            if (count >= i)
                h = i;
        }

        return h;
    }
};

// User function Template for C++
class Solution
{
public:
    // Function to find hIndex
    int hIndex(vector<int> &citations)
    {
        // Using Sorting
        int n = citations.size();

        sort(citations.begin(), citations.end(), greater<int>());

        int h = 0;

        for (int i = 1; i <= n; i++)
        {
            if (citations[i - 1] >= i)
                h = i;
            else
                break;
        }

        return h;
    }
};

// User function Template for C++
class Solution
{
public:
    // Function to find hIndex
    int hIndex(vector<int> &citations)
    {
        // Using Counting Sort
        int n = citations.size();
        vector<int> count(n + 1, 0);

        for (int c : citations)
        {
            if (c >= n)
                count[n]++;
            else
                count[c]++;
        }

        int total = 0;
        for (int i = n; i >= 0; i--)
        {
            total += count[i];
            if (total >= i)
                return i;
        }

        return 0;
    }
};

// User function Template for C++
class Solution
{
public:
    // Function to find hIndex
    int hIndex(vector<int> &citations)
    {
        // Using Counting Sort
        int n = citations.size();
        vector<int> count(n + 1, 0);

        for (int c : citations)
        {
            if (c >= n)
                count[n]++;
            else
                count[c]++;
        }

        int total = 0;
        for (int i = n; i >= 0; i--)
        {
            total += count[i];
            if (total >= i)
                return i;
        }

        return 0;
    }
};

int main()
{
    return 0;
}