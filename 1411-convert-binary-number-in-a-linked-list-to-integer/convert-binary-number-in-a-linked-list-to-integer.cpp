/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int convert(vector<int> arr) {
        int dec = 0;
        int len = arr.size();
        for (int i = 0; i < len; ++i) {
            dec += arr[i] * pow(2, (len - i - 1));
        }
        return dec;
    }
    int getDecimalValue(ListNode* head) {
        vector<int> a;
        
        while (head != nullptr) {
            a.push_back(head->val);
            head = head->next;
        }
        for(auto i:a){
            cout<< i<< " ";
        }
        return convert(a);
    }
};