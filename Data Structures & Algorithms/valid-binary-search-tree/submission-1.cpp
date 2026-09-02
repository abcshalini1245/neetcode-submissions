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
    bool isAns(TreeNode* root, long long min_val, long long max_val){
        if(root == NULL) return true;
        if(root->val <= min_val || root->val >= max_val)
          return false;
        bool left = isAns(root->left, min_val, root->val);
        bool right = isAns(root->right, root->val, max_val);
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        
        return isAns(root,LLONG_MIN,LLONG_MAX);
        

    }
};
