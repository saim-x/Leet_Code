class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;

        vector<vector<int>> freq;
        for(int i=0;i<words.size();i++){
            vector<int> f(26,0);
            for(int j=0;j<words[i].size();j++)
                f[words[i][j]-'a']++;
            freq.push_back(f);
        }
        for(int i=0;i<26;i++){
            int min = freq[0][i];
            for(int j=1;j<freq.size();j++)
                if(freq[j][i]<min)
                    min = freq[j][i];
            for(int j=0;j<min;j++)
                res.push_back(string(1, 'a'+i));
        }
        return res;

    }
};