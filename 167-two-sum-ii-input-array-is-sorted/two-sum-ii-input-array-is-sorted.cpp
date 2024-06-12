class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // APROACH 1
        //  vector<int> ans;
        //  bool flag = false;
        //  for (int i = 0; i < numbers.size() - 1; i++) {
        //      for (int j = i; j < numbers.size(); j++) {
        //          if (numbers[i] + numbers[j] == target && i != j) {
        //              ans.push_back(i + 1);
        //              ans.push_back(j + 1);
        //              flag = true;
        //              break;
        //          }
        //      }
        //      if (flag) {
        //          break;
        //      }
        //  }
        //  return ans;
        // APPROACH 2
        int lp= 0;
        int rp= numbers.size()-1;
        vector<int>ans;
        while(lp<numbers.size()&&rp>0){
            if(numbers[lp]+numbers[rp]==target){
                ans.push_back(lp+1);
                ans.push_back(rp+1);
                break;
            }
            if(numbers[lp]+numbers[rp]<target){
                lp++;
            }
            if(numbers[lp]+numbers[rp]>target){
                rp--;
            }
        }
        return ans;
    }
};