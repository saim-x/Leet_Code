class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // bool f = true;
        // for (int i = 0; i < digits.size(); ++i) {
        //     if (digits[i] != 9)
        //         f = false;
        //         break;
        // }
        // if(f){
        //     vector<int> ans;
        //     ans.push_back(1);
        //     for(int i=0; i<digits.size();++i){
        //         ans.push_back(0);
        //     }
        //     return ans;
        // }

        // if (digits[digits.size() - 1] >= 9) {
        //     int number = digits[digits.size() - 1];
        //     digits.pop_back();
        //     number++;
        //     vector<int> asdf;

        //     while (number > 0) {
        //         asdf.push_back(number % 10);
        //         number /= 10;
        //     }
        //     reverse(asdf.begin(), asdf.end());

        //     for (int digit : asdf) {
        //         digits.push_back(digit);
        //     }
        // } else {
        //     digits[digits.size() - 1]++;
        // }
        // return digits;
        string numberStr;
        for (int digit : digits) {
            numberStr += to_string(digit);
        }

        int n = numberStr.size();
        int carry = 1;

        for (int i = n - 1; i >= 0; --i) {
            int num = numberStr[i] - '0' + carry;
            if (num >= 10) {
                numberStr[i] = '0';
                carry = 1;
            } else {
                numberStr[i] = num + '0';
                carry = 0;
                break;
            }
        }

        if (carry) {
            numberStr.insert(numberStr.begin(), '1');
        }

        vector<int> result;
        for (char ch : numberStr) {
            result.push_back(ch - '0');
        }

        return result;
    }
};