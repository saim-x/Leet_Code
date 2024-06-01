class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
            sort(prices.begin(), prices.end()); 
            int smallest[2];
            smallest[0] = prices[0];
            smallest[1] = prices[1];
            if((smallest[0]+smallest[1])>money){
                return money;
            }else{
                return money-(smallest[0]+smallest[1]);
            }
    }
};