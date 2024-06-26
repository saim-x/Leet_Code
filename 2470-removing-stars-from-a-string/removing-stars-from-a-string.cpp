class Solution {
public:
    string removeStars(string s) {
        vector<char> aa;

        for (char c : s) {
            if (c == '*') {
                if (!aa.empty()) {
                    aa.pop_back(); 
                }
            } else {
                aa.push_back(c);
            }
        }
        return string(aa.begin(), aa.end());
    }
};
