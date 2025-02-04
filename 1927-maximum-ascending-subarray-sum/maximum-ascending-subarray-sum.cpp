#include <bits/stdc++.h>

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // calculating breaking points
        vector<int> bp;
        bp.push_back(0);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                cout << "breaking " << i << "\n";
                bp.push_back(i);
            }
        }
        bp.push_back(nums.size() - 1);
        if (bp.size() == 1)
            return accumulate(nums.begin(), nums.end(), 0);
        vector<int> sums;
        for (int i = 1; i < bp.size(); ++i) {
            if (i == bp.size() - 1) {
                sums.push_back(accumulate(nums.begin() + bp[i - 1],
                                          nums.begin() + bp[i] + 1, 0));
            } else {
                sums.push_back(accumulate(nums.begin() + bp[i - 1],
                                          nums.begin() + bp[i], 0));
            }
        }
        for (auto i : sums) {
            cout << i << " ";
        }
        return *max_element(sums.begin(), sums.end());
    }
};