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
    // TreeNode* func(TreeNode* root, TreeNode* p, TreeNode* q){
    //     if((root->val >= p->val && root->val<=q->val) || 
    //     (root->val <= p->val && root->val>=q->val)) return root;
    //     else if((root->val > p->val && root->val>q->val)){
    //         return func(root->left, p, q);
    //     }else{
    //         return func(root->right, p, q);
    //     }
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val >= p->val && root->val<=q->val) || 
        (root->val <= p->val && root->val>=q->val)) return root;
        else if((root->val > p->val && root->val>q->val)){
            return lowestCommonAncestor(root->left, p, q);
        }else{
            return lowestCommonAncestor(root->right, p, q);
        } 
    }
};
