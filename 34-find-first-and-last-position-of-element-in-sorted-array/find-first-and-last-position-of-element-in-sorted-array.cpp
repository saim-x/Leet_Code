class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        bool f = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                f = true;
                ans.push_back(i);
                break;}
        }
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] == target) {
                ans.push_back(i);
                break;
            }
        }
        if (!f) {
            ans.push_back(-1);
            ans.push_back(-1);
        }

        if (ans.size() == 1) {ans.push_back(ans[0]);}
        return ans;
    }
};