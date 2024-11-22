/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    void inorderTraversalHelper(TreeNode* node){
        if(!node)return;
        inorderTraversalHelper(node->left);
        ans.push_back(node->val);
        inorderTraversalHelper(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversalHelper(root);
        return ans;
    }
};