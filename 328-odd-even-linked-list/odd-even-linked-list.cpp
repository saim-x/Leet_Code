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
    ListNode* oddEvenList(ListNode* head) {
        int a = 1;
        vector<int> arr;
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {

            if (a % 2 == 1) {
                arr.push_back(curr->next->val);
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }

        for (auto i : arr) {
            cout << i;
        }
        ListNode* end = curr;
        if (end == NULL) {
            end = head;
            while (end != NULL && end->next != NULL) {
                end = end->next;
            }
        } else {
            while (end->next != NULL) {
                end = end->next;
            }
        }
        for (auto i : arr) {
            end->next = new ListNode(i);
            end = end->next;
        }

        return head;
    }
};