class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for (int i = 0; i < prices.size(); ++i) {
            bool flag=false;
            int n = prices[i];
            for (int j = i + 1; j < prices.size(); ++j) {
                if (prices[j] <= n) {
                    ans.push_back(n - prices[j]);
                    flag=true;
                    break;
                }
            }
            if(!flag){
                ans.push_back(n);
            }
        }
        return ans;
    }
};
