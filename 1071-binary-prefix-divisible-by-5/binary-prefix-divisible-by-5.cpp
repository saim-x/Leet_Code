#include <bitset>

class Solution {
public:
    // string binaryToDecimal(const string& binaryStr) {
    //     string decimal = "0";
    //     for (char bit : binaryStr) {
    //         int carry = 0;
    //         for (auto& digit : decimal) {
    //             int num = (digit - '0') * 2 + carry;
    //             digit = (num % 10) + '0';
    //             carry = num / 10;
    //         }
    //         if (carry) {
    //             decimal.push_back(carry + '0');
    //         }
    //         if (bit == '1') {
    //             carry = 1;
    //             for (auto& digit : decimal) {
    //                 int num = (digit - '0') + carry;
    //                 digit = (num % 10) + '0';
    //                 carry = num / 10;
    //             }
    //             if (carry) {
    //                 decimal.push_back(carry + '0');
    //             }
    //         }
    //     }
    //     reverse(decimal.begin(), decimal.end());
    //     return decimal;
    // }
    // bool isDivisibleBy5(const string& binaryStr) {
    //     int remainder = 0;
    //     for (char bit : binaryStr) {
    //         remainder = (remainder * 2 + (bit - '0')) % 5;
    //     }
    //     return remainder == 0;
    // }
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        // vector<string> binNums;
        // vector<bool> ans;
        // string temp;
        // // for (int i = 0; i < nums.size(); ++i) {
        // //     temp = "";
        // //     for (int j = 0; j <= i; j++) {
        // //         temp += to_string(nums[j]);
        // //     }
        // //     binNums.push_back(temp);
        // // }
        // string input="";
        // for(auto i:nums){
        //     input+= to_string(i);
        // }
        // for(int i=1; i<=nums.size(); ++i){
        //     temp=input.substr(0, i);
        //     binNums.push_back(temp);
        // }

        // for (auto i : binNums) {
        //     if(isDivisibleBy5(i)){
        //         ans.push_back(true);
        //     }else{
        //         ans.push_back(false);
        //     }
        // }
        // return ans;
        vector<bool> ans;
        int current = 0;
        for (int i = 0; i < nums.size(); ++i) {
            current = ((current * 2) + nums[i]) % 5;
            ans.push_back(current == 0);
        }
        return ans;
    }
};