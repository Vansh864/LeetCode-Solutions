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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
        return {};
        vector<vector<TreeNode*>> node;
        node.push_back({root});
        while(true) {
            vector<TreeNode*> temp;
            for(TreeNode* i : node[node.size() - 1]) {
                if(i->left)
                temp.push_back(i->left);
                if(i->right)
                temp.push_back(i->right);
            }
            if(temp.size() == 0)
            break;
            node.push_back(temp);
        }
        vector<vector<int>> ans;
        for(vector<TreeNode*> i : node) {
            vector<int> temp;
            for(TreeNode* j : i) {
                temp.push_back(j->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};