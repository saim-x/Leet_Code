class Solution {
public:
    bool check(vector<int>& nums) {
        bool fa = false;
        for (auto i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (!fa)
                    fa = true;
                else {
                    return false;
                }
            }
        }
        vector<int>s=nums;
        sort(s.begin(), s.end());
        if(nums == s)return true;
            bool f=false;
        for(int i=0; i<nums.size(); ++i){
            f=false;
            for(int j=0; j<nums.size();j++){
                if(nums[i]!=s[j]){
                    f=true;
                    break;
                }
                i++;
                i%=nums.size();
            }
            if(!f)return true;
        }
        return false;
    }
};