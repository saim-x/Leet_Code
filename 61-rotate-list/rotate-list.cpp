
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
    int getSize(ListNode* node) {
        if (!node)
            return 0;

        return 1 + getSize(node->next);
    }
    vector<int> lltoarr(ListNode* node) {
        vector<int> ans;
        while (node) {
            ans.push_back(node->val);
            node = node->next;
        }
        return ans;
    }
    void rotate(vector<int>& v) {
        int n = v.size();
        int temp = v[n - 1];
        vector<int> w;
        w = v;

        for (int i = 1; i < n; i++) {
            v[i] = w[i - 1];
        }
        v[0] = temp;
    }
    ListNode* con(const vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        ListNode* head = new ListNode(nums[0]);
        ListNode* current = head;
        for (size_t i = 1; i < nums.size(); ++i) {
            current->next = new ListNode(nums[i]);
            current = current->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = getSize(head);
        // for (int i = 0; i <= k % n; ++i) {
        //     ListNode* current = head;
        //     for (int j = 0; j < n; j++) {

        //         ListNode* temp = current;
        //         current = current->next;
        //         if(j==n-1){
        //             head = current;
        //             break;
        //         }
        //         current = temp;
        //     }
        // }
        if(!head)return head;
        vector<int> arr = lltoarr(head);
        for (auto i : arr) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < k % n; ++i) {
            rotate(arr);
            for (auto i : arr) {
                cout << i << " ";
            }
            cout << endl;
        }

        return con(arr);
    }
};