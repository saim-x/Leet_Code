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
 #include <algorithm>
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>arr;
        ListNode* curr= head;
        while(curr!=NULL){
            arr.push_back(curr->val);
            curr = curr->next;
        }
        iter_swap(arr.begin()+k-1, arr.end()-k);
        ListNode* newHead = nullptr;
        ListNode* current = nullptr;
        for(auto i: arr){
            if(newHead==nullptr){
                newHead = new ListNode(i);
                current = newHead;
            }else{
                current->next = new ListNode(i);
                current = current->next;
            }
        }
        return newHead;
    }
};