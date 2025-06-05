#include <iostream>
using namespace std;

class Solution
{
public:
    double solve(double b, long long e)
    {
        if (e == 0)
            return 1.0;

        double half = solve(b, e / 2);
        if (e % 2 == 0)
            return half * half;

        else
            return b * half * half;
    }
    double power(double b, int e)
    {
        if (e == 0)
            return 1.0;

        long long exp = e;
        bool isNegExp = exp < 0;

        if (isNegExp)
            exp = -exp;

        double res = solve(b, exp);

        return isNegExp ? 1.0 / res : res;
    }
};

int main()
{
    return 0;
}