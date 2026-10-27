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
    int h(TreeNode* root) {
        if(root == nullptr)
        return 0;
        return 1 + max(h(root->left), h(root->right));
    }

    void p(TreeNode* root, int node, vector<TreeNode*>& path) {
        if(root == nullptr)
        return;
        path.push_back(root);
        if(root->val == node)
        return;
        p(root->left, node, path);
        if(path[path.size() - 1]->val == node)
        return;
        p(root->right, node, path);
        if(path[path.size() - 1]->val == node)
        return;
        path.erase(path.end() - 1);
        return;
    }

    int amountOfTime(TreeNode* root, int start) {
        vector<TreeNode*> path;
        p(root, start, path);
        TreeNode* node = path[path.size() - 1];
        int ans = max(h(node->left), h(node->right));
        if(start == root->val)
        return ans;
        int n = path.size();
        for(int i = 0; i < n - 1; i++) {
            int temp = n - 1 - i;
            if(path[i]->left && path[i]->right) {
                if(path[i]->left == path[i + 1]) {
                    temp += h(path[i]->right);
                } else {
                    temp += h(path[i]->left);
                }
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};