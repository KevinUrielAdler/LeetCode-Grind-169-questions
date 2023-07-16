#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        if (prices.size() == 0)
            return res;
        int min = prices[0];
        for (auto i : prices)
        {
            if (i - min > res)
                res = i - min;
            if (i < min)
                min = i;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices);
    return 0;
}
