class Solution {
public:
    vector<pair<char, int>> guide;
    void store() {
        guide.push_back(make_pair('I', 1));
        guide.push_back(make_pair('V', 5));
        guide.push_back(make_pair('X', 10));
        guide.push_back(make_pair('L', 50));
        guide.push_back(make_pair('C', 100));
        guide.push_back(make_pair('D', 500));
        guide.push_back(make_pair('M', 1000));
    }
    int convertor(char c) {
        for (auto i : guide) {
            if (i.first == c) {
                return i.second;
            }
        }
        return -1;
    }
    int romanToInt(string s) {
        store();
        int ans=0;
        for (int i = 0; i < s.length(); ++i) {

            if ((i+1== s.length()) ||convertor(s[i])>=convertor(s[i+1] )){
                cout << convertor(s[i]) << endl;
                ans += convertor(s[i]);                
            }else{
                int less = convertor(s[i+1]) - convertor(s[i]);
                ans+=less;
                i++;
            }
        }
        return ans;
    }
};