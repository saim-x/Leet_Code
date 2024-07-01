
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss = processString(s);
        string tt = processString(t);
        return ss == tt;
    }

private:
    string processString(string str) {
        string result;
        for (char ch : str) {
            if (ch == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }
};