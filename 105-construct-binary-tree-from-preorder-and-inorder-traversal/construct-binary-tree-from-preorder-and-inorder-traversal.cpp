class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r, int& preIdx, unordered_map<int, int>& inorderMap) {
        if (l > r) return nullptr;
        
        int rootVal = preorder[preIdx++];
        TreeNode* node = new TreeNode(rootVal);
        
        // Find the index of the root in O(1) time
        int idx = inorderMap[rootVal];
        
        node->left = build(preorder, inorder, l, idx - 1, preIdx, inorderMap);
        node->right = build(preorder, inorder, idx + 1, r, preIdx, inorderMap);
        
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        int preIdx = 0;
        return build(preorder, inorder, 0, inorder.size() - 1, preIdx, inorderMap);
    }
};