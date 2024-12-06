class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int n = stones.size()-1;
            int dif;
            if (stones[n] >= stones[n - 1]) {
                dif = abs(stones[n] - stones[n-1]);
            }

            stones.erase(stones.end() - 1);
            for(auto i:stones){
                cout << i << " ";
            }
            cout << endl;
            stones.erase(stones.end() - 1);
            for(auto i:stones){
                cout << i << " ";
            }
            if (dif != 0) {
                stones.push_back(dif);
            }
        }
        if(!stones.size()){
            return 0;
        }
        return stones[0];
    }
};