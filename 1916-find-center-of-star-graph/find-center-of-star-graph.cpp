#include <unordered_map>
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for (int i = 0; i < edges.size(); ++i) {
            for (int j = 0; j < edges[i].size(); ++j) {
                if (mp.find(edges[i][j]) == mp.end())
                    mp.insert(make_pair(edges[i][j], 1));
                else {
                    mp[edges[i][j]]++;
                }
            }
        }

        std::unordered_map<int, int>::iterator it = mp.begin();
        int a = it->second;
        int b = it->first;

        for (const auto& it : mp) {
            if (a < it.second) {
                a = it.second;
                b = it.first;
            }
        }

        return b;
    }
};