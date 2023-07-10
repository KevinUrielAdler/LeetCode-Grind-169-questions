#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int bs(vector<pair<int, int>> &nums, int target, int ini, int fin)
    {
        if (fin < ini)
            return -1;
        int med = (ini + fin) / 2;
        if (nums[med].first == target)
            return nums[med].second;
        else if (nums[med].first < target)
            return bs(nums, target, med + 1, fin);
        return bs(nums, target, ini, med - 1);
    }

    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        size_t tam = nums.size();
        int sec;
        vector<pair<int, int>> sorted_nums;
        for (size_t i = 0; i < tam; i++)
        {
            sorted_nums.push_back(make_pair(nums[i], i));
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        for (size_t i = 0; i < tam; i++)
        {
            sec = target - sorted_nums[i].first;
            sec = bs(sorted_nums, sec, i + 1, tam - 1);
            if (sec != -1)
            {
                res.push_back(sorted_nums[i].second);
                res.push_back(sec);
                return res;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = sol.twoSum(nums, target);
    cout << ans[0] << " " << ans[1];
    return 0;
}
