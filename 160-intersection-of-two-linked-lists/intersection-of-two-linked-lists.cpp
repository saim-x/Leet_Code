/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode* head) {
    int a = 0;
    ListNode* curr = head;
    while (curr != NULL) {
        curr = curr->next;
        a++;
    }
    return a;
}
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int sizeA = length(headA);
        int sizeB = length(headB);
        int d = 0;
        ListNode* ptr1;
        ListNode* ptr2;
        if (sizeA > sizeB) {
            d = sizeA - sizeB;
            ptr1 = headA;
            ptr2 = headB;
        } else {
            d = sizeB - sizeA;
            ptr1 = headB;
            ptr2 = headA;
        }
        while(d){
            ptr1 = ptr1->next;
            if(ptr1==NULL)return NULL;
            d--;
        }
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1==ptr2){
                return ptr2;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;

        }

        return NULL;
    }
};