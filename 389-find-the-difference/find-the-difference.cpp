class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> sc(2);
        for (auto i : s) {
            sc[0] += i;
        }
        for (auto i : t) {
            sc[1] += i;
        }
        int a = sc[1] - sc[0];
        char ans = (char)a;
        return ans;
    }
};