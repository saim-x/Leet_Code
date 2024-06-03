class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int index=0;
        if(nums.size() == 1){
            return nums[0];
        }
        while(nums[index] == nums[index+1] && index < nums.size()){
            index+=2;

        }
        return nums[index];
    }
};