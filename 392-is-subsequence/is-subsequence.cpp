class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) {
            return false;
        }
        if (s == t) {
            return true;
        }
        // for a
        vector<int> pos;
        for (int j = 0; j < s.size(); j++) {
            for (int i = 0; i < t.size(); i++) {
                if (pos.size() == 0) {
                    if (s[j] == t[i]) {
                        pos.push_back(i);
                        break;
                    }
                } else {
                    if (s[j] == t[i] && pos[pos.size()-1]<i ) {
                        pos.push_back(i);
                        break;
                    }
                }
            }
        }
        if(pos.size()==s.size()){
            return true;
        }else{
            return false;
        }
    }
};