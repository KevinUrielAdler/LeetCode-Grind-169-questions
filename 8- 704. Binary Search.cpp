#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bs(vector<int> &nums, int &target, int ini, int fin) {
        int med = (ini + fin) / 2;

        if (ini == med)
            return (target == nums[ini]) ? ini : (target == nums[fin]) ? fin
                                                                       : -1;

        if (target < nums[med])
            return bs(nums, target, ini, med);
        else if (target > nums[med])
            return bs(nums, target, med, fin);
        else
            return med;
    }

    int search(vector<int> &nums, int target) {
        return bs(nums, target, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << sol.search(nums, target);

    return 0;
}
