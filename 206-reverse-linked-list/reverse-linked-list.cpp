
/**
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        while (head != NULL) {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        head = prev;
        return head;
    }
};