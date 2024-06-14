class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        vector<long long> sum_arr;
        if (k == 0) {
            for(int i = 0; i < nums.size(); i++) {
                ans.push_back(nums[i]);
            }
            return ans;
        }
        if(nums.size() < k || (nums.size() < (2 * k + 1))) {
            for(int i = 0; i < nums.size(); i++) {
                ans.push_back(-1);
            }
            return ans;
        }
        
        int j = 0;
        long long sum = 0;
        for (int i = 0; i < 2 * k + 1; i++) {
            sum += nums[i];
        }
        sum_arr.push_back(sum);

        for (int i = 2 * k + 1; i < nums.size(); i++) {
            sum += nums[i] - nums[i - (2 * k + 1)];
            sum_arr.push_back(sum);
        }

        for (int i = 0; i < k; i++) {
            ans.push_back(-1);
        }
        for (int i = k; i < nums.size() - k; i++) {
            ans.push_back(sum_arr[i - k] / (2 * k + 1));
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(-1);
        }

        return ans;
    }
};