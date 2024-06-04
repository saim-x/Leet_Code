
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        bool flag;
        for (auto i : nums1) {
            for (auto j : nums2) {

                if (i == j) {
                    res.push_back(i);
                    break;
                }
            }
        }
        std::unordered_set<int> seen;
        auto it = res.begin();
        while (it != res.end()) {
            if (seen.find(*it) != seen.end()) {
                it = res.erase(it); 
            } else {
                seen.insert(*it);
                ++it;
            }
        }

        return res;
    }
};