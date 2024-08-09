
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
// class Solution {
//     public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while (fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         return slow;
//     }
// };
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        int n;
        ListNode* curr = head;
        while (curr != NULL) {
            size++;
            curr = curr->next;
        }
        n = (size / 2) + 1;
        curr = head;
        for(int i=0; i<n-1; i++){
            curr= curr->next;
        }
        
        
        return curr;
    }
};