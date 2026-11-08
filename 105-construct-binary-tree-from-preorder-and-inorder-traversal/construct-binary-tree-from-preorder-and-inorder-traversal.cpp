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
    vector<int> sub(vector<int> &vec, int l, int r) {
        vector<int> ans;
        for(int i = l; i <= r; i++) {
            ans.push_back(vec[i]);
        }
        return ans;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
        return nullptr;
        int idx;
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == preorder[0]) {
                idx = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(preorder[0]);
        preorder.erase(preorder.begin());
        if(idx != 0) {
            vector<int> temp = sub(inorder, 0, idx - 1);
            node->left = buildTree(preorder, temp);
        }
        if(idx != inorder.size() - 1) {
            vector<int> temp = sub(inorder, idx + 1, inorder.size() - 1);
            node->right = buildTree(preorder, temp);
        }
        return node;
    }
};