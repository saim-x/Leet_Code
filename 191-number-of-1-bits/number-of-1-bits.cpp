class Solution {
public:
    int decToBinary(int n) {
        int binaryNum[32];

        int i = 0;
        while (n > 0) {
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
        unordered_map<int, int> mp;
        for (int j = i - 1; j >= 0; j--) {
            if (mp.find(binaryNum[j]) == mp.end()) {
                mp.insert(make_pair(binaryNum[j], 1));
            } else {
                mp[binaryNum[j]]++;
            }
        }
        for (const auto& it : mp) {
            if (it.first == 1) {
                return it.second;
            }
        }
        return -1;
    }
    int hammingWeight(int n) { return decToBinary(n); }
};