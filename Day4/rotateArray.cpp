#include <iostream>
using namespace std;

// Juggling Method
class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int> &arr, int d)
    {
        // code here
        int n = arr.size();
        if (n == 0)
            return;

        d = d % n;

        int sets = gcd(n, d);
        for (int i = 0; i < sets; i++)
        {
            int temp = arr[i];
            int j = i;

            while (1)
            {

                int nextIdx = (j + d) % n;
                if (nextIdx == i)
                    break;

                arr[j] = arr[nextIdx];
                j = nextIdx;
            }

            arr[j] = temp;
        }
    }
};

// Block Swap Method
class Solution
{
public:
    int n;

    void swapInRange(vector<int> &nums, int s1, int s2, int k)
    {
        for (int i = 0; i < k; i++)
            swap(nums[s1 + i], nums[s2 + i]);
    }

    void blockSwap(vector<int> &nums, int k)
    {
        if (k == 0 || k == n)
            return;
        int A = k;
        int B = n - k;

        while (A != B)
        {
            if (A < B)
            {
                swapInRange(nums, k - A, k - A + B, A);
                B -= A;
            }
            else
            {
                swapInRange(nums, k - A, k, B);
                A -= B;
            }
        }

        // Final swap when A == B
        swapInRange(nums, k - A, k, A);
    }

    void rotate(vector<int> &nums, int k)
    {
        n = nums.size();
        if (n == 1)
            return;
        k %= n;
        blockSwap(nums, n - k); // Rotate left by (n - k) to achieve right rotation
    }
};

// Reverse Method
void rotateArr(vector<int> &arr, int d)
{
    int n = arr.size();

    // Handle the case where d > size of array
    d %= n;

    // Reverse the first d elements
    reverse(arr.begin(), arr.begin() + d);

    // Reverse the remaining n-d elements
    reverse(arr.begin() + d, arr.end());

    // Reverse the entire array
    reverse(arr.begin(), arr.end());
}

int main()
{
    return 0;
}