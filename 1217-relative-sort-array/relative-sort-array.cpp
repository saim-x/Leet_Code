#include <algorithm>

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr1[j] == arr2[i]) {
                    ans.push_back(arr2[i]);
                }
            }
        }
        vector<int> rem;

        for (int i = 0; i < arr1.size(); i++) {
            auto res = find(ans.begin(), ans.end(), arr1[i]);
            if (res == end(ans)) {
                cout << "Element " << arr1[i] << " is found " << endl;
                rem.push_back(arr1[i]);
            }
        }
        sort(rem.begin(), rem.end());
        for (int i = 0; i < rem.size(); i++) {
            ans.push_back(rem[i]);
        }
        return ans;
    }
};