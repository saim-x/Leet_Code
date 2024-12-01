class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < trust.size(); i++) {
            mp[trust[i][1]]++;
        }
        for (const auto i : mp) {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
        // if (mp.size() > 1) {
        //     return -1;
        // }
        for (auto i : mp) {
            auto check = i;
            cout << check.first;
            bool flag = true;
            for (int i = 0; i < trust.size(); ++i) {
                if (trust[i][0] == check.first) {
                    flag = false;
                    break;
                }
            }
            if (flag && check.second == n - 1) {
                return check.first;
            }
            
        }
        return -1;
    }
};