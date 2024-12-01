class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, char> mp2;

        if (s.length() != t.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp.insert(make_pair(s[i], t[i]));
            } else {
                if (mp.find(s[i])->second != t[i])

                {
                    return false;
                }
            }
        }

        for (int i = 0; i < t.length(); i++) {
            if (mp2.find(t[i]) == mp2.end()) {
                mp2.insert(make_pair(t[i], s[i]));
            } else {
                if (mp2.find(t[i])->second != s[i])

                {
                    return false;
                }
            }
        }
        return true;
    }
};