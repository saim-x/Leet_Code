#include <string>

class Solution {
public:
    int appendCharacters(std::string s, std::string t) {
        int sIndex = 0;
        int tIndex = 0;

        while (sIndex < s.size() && tIndex < t.size()) {
            if (s[sIndex] == t[tIndex]) {
                tIndex++;
            }
            sIndex++; 
        }

        return t.size() - tIndex;
    }
};