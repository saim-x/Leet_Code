class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        if (deck.size() < 2) {
            return false;
        }
        for (int i = 0; i < deck.size(); i++) {
            mp[deck[i]]++;
        }
        vector<int> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.push_back(it->second);
        }
        // int f=ans[0];

        // for(const int& e:ans){
        //     if(e%2!=0 )
        //         return false;
        //     if(f%e)
        // }
        int result = ans[0];
        for (size_t i = 1; i < ans.size(); ++i) {
            result = gcd(result, ans[i]);
            if (result == 1) { 
                break;
            }
        }
        return result>1;
    }
};