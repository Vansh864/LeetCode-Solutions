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
    void p(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if(root == nullptr)
        return;
        path.push_back(root);
        if(root == node)
        return;
        p(root->left, node, path);
        if(path[path.size() - 1] == node)
        return;
        p(root->right, node, path);
        if(path[path.size() - 1] == node)
        return;
        path.erase(path.end() - 1);
        return;
    }

    void down(int k, TreeNode* target, vector<int>& ans) {
        if(k == 0)
        return;
        if(k == 1) {
            if(target->left)
            ans.push_back(target->left->val);
            if(target->right)
            ans.push_back(target->right->val);
        }
        if(target->left)
        down(k - 1, target->left, ans);
        if(target->right)
        down(k - 1, target->right, ans);
    }

    void upper(vector<int>& ans, TreeNode* target, int k, vector<TreeNode*>& path) {
        if(k == 0) {
            ans.push_back(target->val);
            return;
        }
        int i;
        for(int j = 0; j < path.size(); j++) {
            if(target == path[j]) {
                i = j;
                break;
            }
        }
        if(k == 1) {
            if(i != 0)
            ans.push_back(path[i - 1]->val);
            if(path[i]->left && path[i]->right) {
                if(path[i]->left == path[i + 1])
                ans.push_back(path[i]->right->val);
                else
                ans.push_back(path[i]->left->val);
            }
            return;
        }
        if(i != 0)
        upper(ans, path[i - 1], k - 1, path);
        if(path[i]->left && path[i]->right) {
            if(path[i]->left == path[i + 1])
            down(k - 1, target->right, ans);
            else
            down(k - 1, target->left, ans);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0)
        return {target->val};
        vector<TreeNode*> path;
        p(root, target, path);
        vector<int> ans = {};
        if(path.size() != 1) {
            int i;
            for(int j = 0; j < path.size(); j++) {
                if(target == path[j]) {
                    i = j;
                    break;
                }
            }
            if(i != 0)
            upper(ans, path[i - 1], k - 1, path);
        }
        down(k, target, ans);
        return ans;
    }
};