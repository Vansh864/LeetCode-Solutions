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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
        return {};
        vector<vector<TreeNode*>> node;
        node.push_back({root});
        bool isOpp = true;
        while(1) {
            vector<TreeNode*> temp;
            if(!isOpp) {
                for(int i = node[node.size() - 1].size() - 1; i >= 0; i--) {
                    if(node[node.size() - 1][i]->left)
                    temp.push_back(node[node.size() - 1][i]->left);
                    if(node[node.size() - 1][i]->right)
                    temp.push_back(node[node.size() - 1][i]->right);
                }
            } else {
                for(int i = node[node.size() - 1].size() - 1; i >= 0; i--) {
                    if(node[node.size() - 1][i]->right)
                    temp.push_back(node[node.size() - 1][i]->right);
                    if(node[node.size() - 1][i]->left)
                    temp.push_back(node[node.size() - 1][i]->left);
                }
            }
            isOpp = !isOpp;
            if(temp.size() == 0)
            break;
            node.push_back(temp);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < node.size(); i++) {
            vector<int> temp;
            for(int j = 0; j < node[i].size(); j++) {
                temp.push_back(node[i][j]->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};