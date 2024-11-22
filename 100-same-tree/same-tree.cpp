/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<pair<int, int>> tree1;
    vector<pair<int, int>> tree2;
    int p1 = 0;
    int p2 = 0;

    void inH(TreeNode* node) {
        if (!node) {
            pair<int, int> temp;
            temp.first = 0;
            temp.second = p1;

            tree1.push_back(temp);
            p1++;
            return;
        }
        

        inH(node->left);
        pair<int, int> temp;
        temp.first = node->val;
        temp.first = p1;
        tree1.push_back(temp);
        inH(node->right);
        p1++;
    }
    void inH2(TreeNode* node) {
        if (!node) {
             pair<int, int> temp;
            temp.first = 0;
            temp.second = p2;

            tree2.push_back(temp);
            p2++;
            return;
        }
        inH2(node->left);
        pair<int, int> temp;
        temp.first = node->val;
        temp.first = p2;
        tree2.push_back(temp);
        inH2(node->right);
        p2++;
    }

    vector<pair<int, int>> tree1b;
    vector<pair<int, int>> tree2b;
    int p1b = 0;
    int p2b = 0;

    void inHb(TreeNode* node) {
        if (!node) {
            pair<int, int> temp;
            temp.first = 0;
            temp.second = p1b;

            tree1b.push_back(temp);
            p1b++;
            return;
        }
        

        pair<int, int> temp;
        temp.first = node->val;
        temp.first = p1b;
        tree1b.push_back(temp);
        inHb(node->left);
        inHb(node->right);
        p1b++;
    }
    void inH2b(TreeNode* node) {
        if (!node) {
             pair<int, int> temp;
            temp.first = 0;
            temp.second = p2b;

            tree2b.push_back(temp);
            p2b++;
            return;
        }
        pair<int, int> temp;
        temp.first = node->val;
        temp.first = p2b;
        tree2b.push_back(temp);
        inH2b(node->left);
        inH2b(node->right);
        p2b++;
    }
    bool flag = true;
    bool checker(TreeNode* p, TreeNode* q) {
        if (!p && !q && !p->left && !q->left && !p->right && !q->right) {
            if (p->left->val != q->left->val) {
                flag = false;
                return false;
            }
            if (p->right->val != q->right->val) {
                flag = false;
                return false;
            }
            checker(p->left, q->left);
            checker(p->right, q->right);
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // inH(p);
        // inH2(q);
        // inHb(p);
        // inH2b(q);
        // for(auto i:tree1){
        //     cout << i.first<< i.second<< " ";
        // }
        // cout << endl;
        // for(auto i:tree2){
        //     cout << i.first<< i.second<< " ";
        // }
        // cout << endl;
        // for(auto i:tree1b){
        //     cout << i.first<< i.second<< " ";
        // }
        // cout << endl;
        // for(auto i:tree2b){
        //     cout << i.first<< i.second<< " ";
        // }
        // if (tree1 == tree2 && tree1b == tree2b) {
        //     return true;
        // }
        // return false;
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
    
    }
};