/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    void path(vector<TreeNode*> &vec, TreeNode* root, TreeNode* node) {
        if(root == nullptr)
        return;
        vec.push_back(root);
        if(root == node)
        return;
        if(root->left)
        path(vec, root->left, node);
        if(vec[vec.size() - 1] == node)
        return;
        else if(root->right)
        path(vec, root->right, node);
        if(vec[vec.size() - 1] == node)
        return;
        vec.erase(vec.end() - 1);
        return;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a;
        vector<TreeNode*> b;
        path(a, root, p);
        path(b, root, q);
        TreeNode* ans;
        for(int i = 0, j = 0; i < a.size() && j < b.size(); i++, j++) {
            if(a[i] == b[j])
            ans = a[i];
        }
        return ans;
    }
};