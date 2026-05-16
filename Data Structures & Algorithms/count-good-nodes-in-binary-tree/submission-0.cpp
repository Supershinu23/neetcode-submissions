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
    int ans = 0 ;
    void func(TreeNode* root, int c){
        if(!root)return ;

        if(root->val >= c){
            ans++;
            c = root->val;
        }
        func(root->left, c);
        func(root->right, c);

    }
    int goodNodes(TreeNode* root) {
        func(root, root->val);
        return ans;
    }
};
