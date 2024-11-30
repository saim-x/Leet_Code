class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedScore = score;
        sort(sortedScore.rbegin(), sortedScore.rend());

        unordered_map<int, int> rank;
        for (int i = 0; i < sortedScore.size(); ++i) {
            rank[sortedScore[i]] = i + 1;
        }

        vector<string> result;
        for (int s : score) {
            int r = rank[s];
            if (r == 1) {
                result.push_back("Gold Medal");
            } else if (r == 2) {
                result.push_back("Silver Medal");
            } else if (r == 3) {
                result.push_back("Bronze Medal");
            } else {
                result.push_back(to_string(r));
            }
        }

        return result;
    }
};
