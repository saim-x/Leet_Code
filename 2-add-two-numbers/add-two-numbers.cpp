#include <iostream>
#include <vector>
#include <algorithm>
#include <string>



std::string vectToString(const std::vector<int>& vec) {
    std::string result;
    for (auto num : vec) {
        result += std::to_string(num);
    }
    return result;
}

std::vector<int> stringToVector(const std::string& str) {
    std::vector<int> vec;
    for (char c : str) {
        vec.push_back(c - '0');
    }
    return vec;
}

std::string addStrings(const std::string& num1, const std::string& num2) {
    std::string result;
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int n1 = (i >= 0) ? num1[i--] - '0' : 0;
        int n2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = n1 + n2 + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::vector<int> arr;
        ListNode* curr = l1;
        while (curr != nullptr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        std::vector<int> arr2;
        ListNode* curr2 = l2;
        while (curr2 != nullptr) {
            arr2.push_back(curr2->val);
            curr2 = curr2->next;
        }

        std::reverse(arr.begin(), arr.end());
        std::reverse(arr2.begin(), arr2.end());

        std::string num1 = vectToString(arr);
        std::string num2 = vectToString(arr2);

        std::string sum = addStrings(num1, num2);

        std::vector<int> an = stringToVector(sum);
        std::reverse(an.begin(), an.end());

        ListNode* newHead = nullptr;
        ListNode* current = nullptr;
        for (auto val : an) {
            if (newHead == nullptr) {
                newHead = new ListNode(val);
                current = newHead;
            } else {
                current->next = new ListNode(val);
                current = current->next;
            }
        }
        return newHead;
    }
};
