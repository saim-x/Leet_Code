class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) return b;
        if (b.empty()) return a;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string result;
        int carry = 0;
        int i = 0;
        
        while (i < a.size() || i < b.size() || carry) {
            int digitSum = carry;
            if (i < a.size()) digitSum += a[i] - '0';
            if (i < b.size()) digitSum += b[i] - '0';
            
            result.push_back((digitSum % 2) + '0');
            
            carry = digitSum / 2;
            ++i;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
