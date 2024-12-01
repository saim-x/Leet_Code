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
        auto i1 = mp.begin();
        auto i2 = mp2.begin();
        // while (i1 != mp.end() && i2 != mp2.end()) {
        //     if (i1->first != i2->second || i1->second != i2->first) {
        //         cout << "yeha";

        //         return false;
        //     }
        //     ++i1;
        //     ++i2;
        // }
        return true;
    }
};