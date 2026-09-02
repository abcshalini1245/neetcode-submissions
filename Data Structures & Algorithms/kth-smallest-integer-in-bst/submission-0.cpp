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
private:
    void inorder(TreeNode* root, vector<int> & inordered){
        if(root == NULL) return;
        inorder(root->left,inordered);
        inordered.push_back(root->val);
        inorder(root->right,inordered);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
     vector<int>inordered;
     inorder(root,inordered);
     return inordered[k-1];   
    }
};
