class Solution {
public:
    bool dup(int n, vector<int>& arr) {
        cout << n ;
        for (int i=0; i<arr.size();++i) {
            if (n == arr[i]) {
                return true;
            }
        }
        return false;
    }
    int thirdMax(vector<int>& nums) {
        vector<int> r;
        for (auto i : nums) {
            if (!dup(i, r)) {
                r.push_back(i);
            }
        }
        
        sort(r.rbegin(), r.rend());
        if (r.size() >= 3) {
            return r[2];
        }
        return r[0];
    }
};