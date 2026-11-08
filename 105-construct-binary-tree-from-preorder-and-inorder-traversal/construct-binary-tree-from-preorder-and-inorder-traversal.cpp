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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if(preorder.size() == 0)
        return nullptr;
        int idx;
        for(int i = l; i < r; i++) {
            if(inorder[i] == preorder[0]) {
                idx = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(preorder[0]);
        preorder.erase(preorder.begin());
        if(idx != l) {
            node->left = build(preorder, inorder, l, idx - 1);
        }
        if(idx != r) {
            node->right = build(preorder, inorder, idx + 1, r);
        }
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};