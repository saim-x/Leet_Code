#include <sstream>
#include <unordered_set>

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        string ans;
        vector<string> words;

        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = 1; j <= words[i].size(); j++) {
                if (dict.find(words[i].substr(0, j)) != dict.end()) {
                    words[i] = words[i].substr(0, j);
                    break;
                }
            }
        }

        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1) {
                ans += " ";
            }
        }

        return ans;
    }
};

