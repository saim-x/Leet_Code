#include <cctype> // for std::isdigit

class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        std::vector<int> ans;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                if (ans.size() >= 2) {
                    int a = ans[ans.size() - 1] + ans[ans.size() - 2];
                    ans.push_back(a);
                }
            } else if (operations[i] == "D") {
                if (ans.size() >= 1) {
                    int a = 2 * (ans[ans.size() - 1]);
                    ans.push_back(a);
                }
            } else if (operations[i] == "C") {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            } else {
                    int num = std::stoi(operations[i]);
                    ans.push_back(num);
                
            }
        }
        int res = 0;
        for (int i = 0; i < ans.size(); i++) {
            res += ans[i];
        }
        return res;
    }
};
