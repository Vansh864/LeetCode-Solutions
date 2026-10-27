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
        return 1 + h(root->left);
    }

    bool check(TreeNode* root, int h) {
        TreeNode* temp = root;
        for(int i = 1; i <= h; i++) {
            if(!temp)
            return false;
            temp = temp->right;
        }
        if(!temp) return true;
        return false;
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr)
        return 0;
        int height = h(root);
        if(height == 1)
        return 1;
        if(check(root, height))
        return pow(2, height) - 1;
        int st = 1, end = pow(2, height - 1);
        TreeNode* temp = root;
        int i = height - 1;
        while(st != end) {
            if(check(temp->left, i)) {
                st = (end + 1 + st) / 2;
                temp = temp->right;
            } else {
                end = (st - 1 + end) / 2;
                temp = temp->left;
            }
            i--;
        }
        return st - 1 + pow(2, height - 1) - 1;
    }
};