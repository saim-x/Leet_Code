class Solution {
public:
    bool f(vector<int>& arr, int n) {
        for (auto i : arr) {
            {
                if (n == i)
                    return true;
            }
        }
        return false;
    }
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            if (!f(nums, i)) {
                return i;
            }
        }
        return 0;
    }
};