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
    int getHeight(TreeNode* node, bool& isbal) {
        if (!node) {
            return 0;
        }

        int leftHeight = getHeight(node->left, isbal);
        int rightHeight = getHeight(node->right, isbal);

        if (std::abs(leftHeight - rightHeight) > 1) {
            isbal = false;
        }
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        bool is = true;
        int height = getHeight(root, is);
        isBalanced(root->left);
        isBalanced(root->right);
        return is;
    }
};